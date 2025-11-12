#include<bits/stdc++.h>
using namespace std;
int t,n,ans,u,v,w;
struct lmx{
	int a,b,c,d,e;
	bool operator<(lmx x){
		return d-e>x.d-x.e;
	}
}s[100002];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=u=v=w=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			s[i].d=max({s[i].a,s[i].b,s[i].c}),s[i].e=s[i].a+s[i].b+s[i].c-s[i].d-min({s[i].a,s[i].b,s[i].c});
		}
		sort(s+1,s+n+1);
		for(int i=1;i<=n;i++){
			if(s[i].d==s[i].a&&u<n/2)ans+=s[i].d,u++;
			else if(s[i].d==s[i].b&&v<n/2)ans+=s[i].d,v++;
			else if(s[i].d==s[i].c&&w<n/2)ans+=s[i].d,w++;
			else ans+=s[i].e;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
