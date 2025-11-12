#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105],m,n,cmt=1,ans,c,r,f=0,s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=m*n;
	for(int i=1;i<=s;i++) cin>>b[i];
	ans=b[1];
	sort(b+1,b+s+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(b[cmt]==ans){
					c=i,r=j;
					cout<<c<<" "<<r;
					f=1;
					break;
				}
				cmt++;
			}
		}else{
			for(int k=n;k>=1;k--){
				if(b[cmt]==ans){
					c=i,r=k;
					cout<<c<<" "<<r;
					f=1;
					break;
				}
				cmt++;
			}
		}
		if(f==1) break;
	}
	return 0;
}
