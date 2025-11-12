#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
#define int long long
struct node{
	int val,id;
}a[N];
int tot,c[N][5],n,ans,id=-1,f[N];
vector<int> g[N]; 
bool cmp(node a,node b){
	return a.val>b.val;
}
bool cmp1(int a,int b){
	return a>b;
}
void Clear(){
	for(int i=1;i<=n;i++)	g[i].clear();
	id=-1,ans=0,tot=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
	
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)	scanf("%lld",&a[j].val),a[j].id=j,c[i][j]=a[j].val;
			sort(a+1,a+3+1,cmp);
			ans+=a[1].val,g[a[1].id].push_back(i);
			if(g[a[1].id].size()>=(n/2))	id=a[1].id;	
			
			
			
		}
		
		if(id==-1)	{printf("%lld\n",ans),Clear();continue;}
		
		
		for(int i=0;i<g[id].size();i++){
			int now=g[id][i],pre=-LLONG_MAX;
			for(int j=1;j<=3;j++){
				if(j==id)	continue;
				pre=max(pre,c[now][j]-c[now][id]);
			}
			tot++,f[tot]=pre;
			
		}
		
		
		sort(f+1,f+tot+1,cmp1); int prenow=g[id].size();
		
		
		int num=1;
		while(prenow>(n/2)){
			ans+=f[num],num++,prenow--;
			
			
		}
		printf("%lld\n",ans);
		Clear();
	}
}
/*
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
