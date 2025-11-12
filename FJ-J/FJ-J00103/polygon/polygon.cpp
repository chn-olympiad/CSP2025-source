#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,P=131;
const int mod=998244353;

int n,ans;
int a[N],B[N]={0};
bool vis[N];

map<int,bool> buk;

bool check(int b[],int len_b){//是否能拼成多边形 
	if(len_b<3)return 0;//边数不足，无法构成多边形 
	
	int h=0,sum=0;
	int maxn=-2147483648;
	
	sort(b+1,b+len_b+1);
	for(int i=1;i<=len_b;i++){
		h=h*P+b[i];
		
		maxn=max(maxn,a[b[i]]);
		sum+=b[a[i]];
	}
	
	if(sum>maxn*2){//能组成多边形
		if(buk[h]==1)return 0;//已有重复的多边形
		buk[h]=1;
		return 1;
	}
	return 0;
}

void dfs(int x,int b[],int cntb){
	if(x==n+1)return ;
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		b[++cntb]=i;
		
		//判断是否能组成多边形 
		if(check(b,cntb)){
//			for(int i=1;i<=n;i++)printf("%d ",b[i]);
//			printf("\n");
			(ans+=1)%=mod;
		}
		
		//深搜 
		dfs(x+1,b,cntb);
		
		//回溯 
		vis[i]=0;
		cntb--;
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<3){
		printf("%d",ans);
		return 0;
	}
	dfs(0,B,0);
	printf("%d",ans);
	return 0;
}
