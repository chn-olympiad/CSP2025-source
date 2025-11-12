// 盘州市第二中学 何忠灿 GZ-S00025
#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,PII> PLP;

const int N=1e5+10;

int T;
int n;
LL s[N][4];
PLP a[N*3];
int cnt[4];
bool st[N*3];
LL sum;

//LL dfs(int u,int cnt1,int cnt2,int cnt3,LL res){
//	if(u==n)return sum;
//	else{
//		if(cnt1+1<=n/2)sum=max(sum,dfs(u+1,cnt1+1,cnt2,cnt3,res+s[u+1][1]));
//		if(cnt2+1<=n/2)sum=max(sum,dfs(u+1,cnt1,cnt2+1,cnt3,res+s[u+1][2])); 
//		if(cnt3+1<=n/2)sum=max(sum,dfs(u+1,cnt1,cnt2,cnt3+1,res+s[u+1][3]));
//	}
//		
//    return sum;
//}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		
		int m=n/2;
		memset(st,0,sizeof st);
		memset(cnt,0,sizeof cnt);
		LL ans=0;
		
//		if(n<=30){
//			for(int i=1;i<=n;i++)
//			    scanf("%lld%lld%lld",&s[i][1],&s[i][2],&s[i][3]);
//			ans=max(ans,dfs(0,0,0,0,0));
//			printf("%lld\n",ans);
//		}else{
			for(int i=1;i<=n*3;i++){
				scanf("%lld",&a[i].x);
				if(i%3==0)a[i].y.x=i/3;
				else a[i].y.x=i/3+1;
				if(i%3==0)a[i].y.y=3;
				else a[i].y.y=i%3;
			}
				
			sort(a+1,a+n*3+1);
			
			for(int i=n*3;i>=1;i--){
				int id=a[i].y.x,d=a[i].y.y;
				if(st[id])continue;
				st[id]=true;
				if(cnt[d]<m){
					cnt[d]++;
					ans+=a[i].x;
				}
			}
			printf("%lld\n",ans);
		//}
	}
    
    return 0;
}
