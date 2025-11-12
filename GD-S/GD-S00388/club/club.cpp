#include<bits/stdc++.h>
using namespace std;
using ll=long long;
/*
在光绪二十六年，
神助拳义和团 ，
扶清  灭洋，
五十五天在北京 
*/
struct node{
	ll a,b,c,d,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll s[n/2+5];
		ll u[n/2+5];
		ll v[n/2+5];
		memset(s,0,sizeof s);
		memset(u,0,sizeof u);
		memset(v,0,sizeof v);
		node g[1005];
		for(int i=1;i<=n;i++){
			cin>>g[i].a>>g[i].b>>g[i].c;
			g[i].d=max(g[i].a,max(g[i].b,g[i].c));
			if(g[i].a==g[i].d){
				g[i].e=1;
			}else if(g[i].b==g[i].d){
				g[i].e=2;
			}else{
				g[i].e=3;
			}
		}
		int len1=0,len2=0,len3=0;
	    for(int i=1;i<=n;i++){
			if(g[i].e==1){
				if(len1<=n/2){
					s[len1++]=g[i].d;
				}else{
					sort(s,s+len1-1);
					if(g[i].d>s[0]){
						s[0]=g[i].d;
						
					}
				}
			}else if(g[i].e==2){
				if(len2<=n/2){
					u[len2++]=g[i].d;
				}else{
					sort(u,u+len2-1);
					if(g[i].d>u[0]){
						u[0]=g[i].d;
					}
				}
			}else{
				if(len3<=n/2){
					v[len3++]=g[i].d;
				}else{
					sort(v,v+len3-1);
					if(g[i].d>v[0]){
						v[0]=g[i].d;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<n/2;i++){
			if(s[i]!=64){
				ans+=s[i];
			}
		}
		for(int i=0;i<n/2;i++){
			if(u[i]!=64){
				ans+=u[i];
			}
		}
		for(int i=0;i<n/2;i++){
			if(v[i]!=64){
				ans+=v[i];
			}
		}
		cout<<ans<<endl;
		
	} 
	fclose(stdin);
	fclose(stdout);
	
} 
