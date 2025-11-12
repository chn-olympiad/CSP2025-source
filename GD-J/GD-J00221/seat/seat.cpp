#include<bits/stdc++.h>
using namespace std;
long long arr[15][15],li[225],n,m,f=1,l=1,h,flag=1,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>li[i];
	ans=li[1];
	sort(li+1,li+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(flag==1)h++;
		if(flag==0)h--;
		if(f%2!=0){
			if(h>m){
				h=m;
				l++;
				f++;
				flag=0;
			}
		}
		if(f%2==0){
			if(h<1){
				h=1;
				l++;
				f++;
				flag=1;
			}
		}
		arr[h][l]=li[i];
		if(li[i]==ans){
			cout<<l<<" "<<h;
			break;
		}
	}
	return 0;
}
