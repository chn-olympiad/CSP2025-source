#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct mem{
	int a,b,c,vis;
}f[N];
//int g[210][210][210];
int n,ans,maxn=-1,t;
bool cmp1(mem a,mem b){
	return a.a>b.a;
}
bool cmp2(mem a,mem b){
	if(!a.vis&&!b.vis)return a.b>b.b;
	return a.vis>b.vis;
}

void dfs(int x,int y,int z){
	if(x>t||y>t||z>t)return ;
	if(x+y+z==n){
		maxn=max(ans,maxn);
//		cout<<maxn<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		//cout<<ans<<endl;
		if(f[i].vis)continue;
		for(int j=1;j<=3;j++){
			if(f[i].vis==0){
				f[i].vis=1;
				if(j==1){
					ans+=f[i].a;
					maxn=max(ans,maxn);
					dfs(x+1,y,z);
					ans-=f[i].a;f[i].vis=0;
				}
				else if(j==2){
					ans+=f[i].b;
					maxn=max(ans,maxn);
					dfs(x,y+1,z);
					ans-=f[i].b;f[i].vis=0;
				}
				else if(j==3){
					ans+=f[i].c;
					maxn=max(ans,maxn);
					dfs(x,y,z+1);
					ans-=f[i].c;f[i].vis=0;
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		ans=0,maxn=-1;
		cin>>n;
		t=n/2;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
		}
		if(n==2){
			cout<<max(f[1].a+f[2].b,max(f[1].a+f[2].c,max(f[2].a+f[1].b,max(f[2].a+f[1].c,max(f[1].b+f[2].c,f[1].c+f[2].b)))))<<endl;
		}
		else if(n<=20){
			dfs(0,0,0);
			cout<<maxn<<endl;
		}
		else{
			if(f[1].b==f[1].c==0){
				sort(f+1,f+n+1,cmp1);ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=f[i].a;
				}
				cout<<ans<<endl;
			}
			else{
				ans=0,maxn=-1;
				for(int i=0;i<=n/2;i++){
					for(int j=i+1;j<=n/2+i;j++){
						if(j+n/2<=n)ans+=f[j].a+f[j+n/2].b;
						else ans+=f[j].a+f[(j+n/2)%n].b;
					}
					maxn=max(ans,maxn);ans=0,maxn=-1;
				}
				cout<<maxn<<endl;
			}
		}
	}
	return 0;
}
