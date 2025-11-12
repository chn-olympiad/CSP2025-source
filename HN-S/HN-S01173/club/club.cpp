#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+10;

struct node{
	int a,b,c;
};
int n,ans;
node man[maxn];
bool isa=1,isb=1;
//luogu uid=930075

int id2num(node t,int i){
	if (i==1)return t.a;
	if (i==2)return t.b;
	if (i==3)return t.c;
}

int use[5];

void dfs(int u,int num){
//	printf("[debug]u=%d num=%d\n",u,num);
//出的题真的太好了
//-J T3,T4=DP
//-S T1=DP
//T2=prim
//非常好
//AFO 
//拿点性质分吧 
	if (u==n+1){
		ans=max(ans,num);
		return;
	}
//	if (num<ans)return;
	for (int i=1;i<=3;++i){
		if (use[i]<n/2)++use[i],dfs(u+1,num+id2num(man[u],i)),--use[i];
	}
	return ;
}

bool isacmp(node a,node b){
	return a.a>b.a;
}

void cale(){
	ans=0;
	cin>>n;
	memset(use,0,sizeof(use));
	for (int i=1;i<=n;++i){
		cin>>man[i].a>>man[i].b>>man[i].c;
		if (man[i].b!=0||man[i].c!=0)isa=0;
		if (man[i].c!=0)isb=0;
	}
	
	if (!isa&&!isb)dfs(1,0),cout<<ans<<endl;
	else {
		if (isa){
			sort(man+1,man+1+n,isacmp);
			for (int i=1;i<=n/2;++i)ans+=man[i].a;
			cout<<ans<<endl;
		}
		else if (isa){
			//.c=0
			
		}
	}
	return ;
} 
/*
int x=0,y=0,z=0;
*/
signed main(){
	freopen("club.in","r",stdin);
//	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;cin>>t;
	while (t--)cale();
	return 0;

}
/*
1
6
9 0 0
1 0 0
7 0 0
8 0 0
1 0 0
4 0 0
*/
