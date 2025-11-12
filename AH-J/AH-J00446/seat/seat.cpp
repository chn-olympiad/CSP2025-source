#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],tmp,c=1,r=1;
bool flag=false;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			cout<<c<<" "<<r;
			break;
		}
		if(flag==false){
			r++;
			if(r==n+1){
				c++;
				r=n;
				flag=true;
			}
		}
		else{
			r--;
			if(r==0){
				c++;
				r=1;
				flag=false;
			}
		}
	}
	return 0;
}
