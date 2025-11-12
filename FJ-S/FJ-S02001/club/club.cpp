#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}z[100005];
struct c1{
	int y,u,p;
}c[100005];
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>z[i].a>>z[i].b>>z[i].c;
			c[i].y=z[i].a-z[i].b;
			c[i].u=z[i].a-z[i].c;
			c[i].p=z[i].b-z[i].c;
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						if(i==1&&j==2){
							ans=max(ans,z[1].a+z[2].b);
						}
						if(i==1&&j==3){
							ans=max(ans,z[1].a+z[2].c);
						}
						if(i==2&&j==1){
							ans=max(ans,z[1].b+z[2].a);
						}
						if(i==2&&j==3){
							ans=max(ans,z[1].b+z[2].c);
						}
						if(i==3&&j==1){
							ans=max(ans,z[1].c+z[2].a);
						}
						if(i==3&&j==2){
							ans=max(ans,z[1].c+z[2].b);
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		
		
	}
	return 0;
}
