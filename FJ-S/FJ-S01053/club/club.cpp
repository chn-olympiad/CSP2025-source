#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int a,b,c;
}e[200005];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		memset(e,0,sizeof(e));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;	
		}
		if(e[1].a+e[2].b>ans){
			ans=e[1].a+e[2].b;
		}
		if(e[1].a+e[2].c>ans){
			ans=e[1].a+e[2].c;
		}
		if(e[1].b+e[2].a>ans){
			ans=e[1].b+e[2].a;
		}
		if(e[1].b+e[2].c>ans){
			ans=e[1].b+e[2].c;
		}
		if(e[1].c+e[2].a>ans){
			ans=e[1].a+e[2].c;
		}
		if(e[1].c+e[2].b>ans){
			ans=e[1].c+e[2].b;
		}
		cout<<ans;
	}
	return 0;
} 
