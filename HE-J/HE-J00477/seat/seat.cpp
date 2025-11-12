#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cj,mode=1,c=1,r=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1;
	while(a[i]!=cj){
		if(mode==1){
			r++;
		}else{
			r--;
		}
		if(r>n||r<1){
			if(mode==1){
				r--;
			}else{
				r++;
			}
			mode+=1;
			mode%=2;
			c++;
		}
		i++;
	}
	cout<<c<<" "<<r;
	return 0;
}
