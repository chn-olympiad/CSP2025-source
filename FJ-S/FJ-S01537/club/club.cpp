#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Code ios::sync_with_stdio(0);
#define with cin.tie(0);
#define ZhouShen cout.tie(0);
#define int long long
using namespace std;
int T,n,status1,status2,cnt[5],a[3][100010],dp[100010],ans=0;
struct node{
	int id,l;
}tmp[100010];
void read(int&a){
	int s=0,w=1;
	char ch;
	ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-')w=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	a=s*w;
}
bool cmp(node alpha,node beta){
	return alpha.l>beta.l;
}
void dfs(int dep,int res){
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			if(dep==n)ans=max(ans,res+a[i][dep]);
			else dfs(dep+1,res+a[i][dep]);
			cnt[i]--;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Code with ZhouShen
	read(T);
	while(T--){
		ans=0;
		status1=1;
		status2=1;
		read(n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				read(a[j][i]);
			}
			if(a[2][i]!=0||a[3][i]!=0)status1=0;
			if(a[3][i]!=0)status2=0;
		}
		if(status1==1){
			sort(a[1]+1,a[1]+1+n);
			for(int i=n;i>n/2;i--){
				ans+=a[1][i];
			}
			cout<<ans<<"\n";
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		if(n<=30)dfs(1,0);
		else{
			for(int i=1;i<=n;i++){
				dp[i]=a[1][i];
				tmp[i].l=a[2][i]-a[1][i];
				tmp[i].id=i;
			}
			sort(tmp+1,tmp+1+n,cmp);
			for(int i=1;i<=n/2;i++)
				dp[tmp[i].id]+=tmp[i].l;
			for(int i=1;i<=n;i++){
				tmp[i].l=a[3][i]-dp[i];
				tmp[i].id=i;
				ans+=dp[i];
			}
			sort(tmp+1,tmp+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				if(ans+tmp[i].l>ans)ans+=tmp[i].l;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
