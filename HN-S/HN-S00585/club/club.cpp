#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
int n,t1,t2,t3,q[200001],p[200001],d[200001],pq[200001],sg,tg;
struct edge{int a,b,c;}e[200001];
void solve(){
	t1=t2=t3=0;
	sg=0;tg=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e[i].a>>e[i].b>>e[i].c;
		if(e[i].a>e[i].b){
			if(e[i].a>e[i].c)q[++t1]=i,sg+=e[i].a;
			else d[++t3]=i,sg+=e[i].c;
		}
		else{
			if(e[i].b>e[i].c)p[++t2]=i,sg+=e[i].b;
			else d[++t3]=i,sg+=e[i].c;
		}
	}
//	cout<<t1<<" "<<t2<<" "<<t3<<" "<<sg<<endl;
	if(t1>n/2){
		for(int id=1;id<=t1;id++){
			int i=q[id];
			if(e[i].a>e[i].b&&e[i].a>e[i].c){
				if(e[i].c>e[i].b)pq[++tg]=e[i].a-e[i].c;
				else pq[++tg]=e[i].a-e[i].b;
			}
		}
		sort(pq+1,pq+tg+1);
		for(int i=1;i<=t1-n/2;i++)sg-=pq[i];
	}
	else if(t2>n/2){
		for(int id=1;id<=t2;id++){
			int i=p[id];
			if(e[i].b>e[i].a&&e[i].b>e[i].c){
				if(e[i].c>e[i].a)pq[++tg]=e[i].b-e[i].c;
				else pq[++tg]=e[i].b-e[i].a;
			}
		}
		sort(pq+1,pq+tg+1);
		for(int i=1;i<=t2-n/2;i++)sg-=pq[i];
	}
	else{
		for(int id=1;id<=t3;id++){
			int i=d[id];
			if(e[i].c>e[i].a&&e[i].c>e[i].b){
				if(e[i].a>e[i].b)pq[++tg]=e[i].c-e[i].a;
				else pq[++tg]=e[i].c-e[i].b;
			}
		}
		sort(pq+1,pq+tg+1);
		for(int i=1;i<=t3-n/2;i++)sg-=pq[i];
	}
	cout<<sg<<endl;
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
