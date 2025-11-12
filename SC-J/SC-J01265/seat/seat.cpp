#include<bits/stdc++.h>
using namespace std;
int b[105];
int main(){
	bool sum=0;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
   int n,m,ans,x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	ans=b[1];
	sort(b+1,b+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(b[i]==ans) cout<<x<<" "<<y;
	     if(y==m&&sum==0){
			x++;
			sum=1;
		}
		 
		else if(sum==1&&y!=1) y--;
		else if(y==1&&sum==1) {
			x++;
			sum=0;
		}
		else if(sum==0&&y!=m) y++;
	}
	return 0;
}