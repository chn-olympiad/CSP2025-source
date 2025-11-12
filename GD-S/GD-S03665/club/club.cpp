#include<bits/stdc++.h>

using namespace std;

int t,n,ans;
int a[100007];
int b[100007];
int c[100007];
int dp[207][207][207];

struct edge{
	int a,b,c;
}stu[100007];

bool cmp(edge x,edge y){
	if(x.b==0&&x.c==0&&y.b==0&&y.c==0){
		return x.a>y.a;
	}
	if(x.a==y.a){
		return x.b>y.b;
	}else{
		return x.a>y.a;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	
	while(t--){
		//map<int,map<int,map<int,int>>> dp;
		memset(dp,0,sizeof(dp));
		ans=0;
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			stu[i].a=a[i],stu[i].b=b[i],stu[i].c=c[i];
		}
		
		if(n>200){
			sort(stu+1,stu+1+n,cmp);
			int cntx=0,cnty=0,cntz=0;
			for(int i=1;i<=n;i++){
				if(cntx<n/2&&cnty<n/2){
					if(stu[i].b>stu[i].a) cnty+=1,ans+=stu[i].b;
					else cntx+=1,ans+=stu[i].a;
				}
				else if(cntx<n/2) cntx+=1,ans+=stu[i].a;
				else if(cnty<n/2) cnty+=1,ans+=stu[i].b;
				else cntz+=1,ans+=stu[i].c;
			}
			printf("%d\n",ans);
			continue;
		}
		
		for(int i=1;i<=n;i++){
			for(int x=0;x<=i&&x<=n/2;x++){
				for(int y=0;x+y<=i&&y<=n/2;y++){
					int z=i-y-x;
					if(z>n/2) continue;
					
					dp[x][y][z] = max({
						dp[x][y][z],
						(x-1>=0)?(dp[x-1][y][z]+a[i]):0,
						(y-1>=0)?(dp[x][y-1][z]+b[i]):0,
						(z-1>=0)?(dp[x][y][z-1]+c[i]):0
					});
					
					ans=max(ans,dp[x][y][z]);
				}
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
} 
