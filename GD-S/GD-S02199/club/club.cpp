#include<bits/stdc++.h>
using namespace std;
long long n,T,sum,mem[100010][4];
//long long dp[100010][10];
struct P{
	long long x;
	long long y;
	long long z;
	long long xycha;
}a[100010];

bool cmp(P u,P v){
	return u.x>v.x;
}

bool cmp1(P u,P v){
	return u.xycha>v.xycha;
}

void dfs(long long now,long long sa,long long sb,long long sc,long long cnt){
	if(now==n+1){
		sum=max(sum,cnt);
		return ;
	}
	if(sa+1<=n/2) dfs(now+1,sa+1,sb,sc,cnt+a[now].x);
	if(sb+1<=n/2) dfs(now+1,sa,sb+1,sc,cnt+a[now].y);
	if(sc+1<=n/2) dfs(now+1,sa,sb,sc+1,cnt+a[now].z);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool is_A=1,is_B=1;
		for(long long i=1;i<=n;i++){
			mem[i][1]=mem[i][2]=mem[i][3]=0;
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].xycha=abs(a[i].x-a[i].y);
			if(a[i].y!=0||a[i].z!=0) is_A=0;
			if(a[i].z!=0) is_B=0;
//			dp[i][1]=dp[i][2]=dp[i][3]=0;
		}
		if(is_A){
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(long long i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans;
		}
		else if(is_B){
			long long l=0,ans=0,r=0;
			sort(a+1,a+1+n,cmp1);
			for(long long i=1;i<=n;i++){
//				cout<<a[i].x<<" - "<<a[i].y<<" = "<<a[i].xycha<<"\n";
				if(a[i].x>=a[i].y&&l+1<=n/2||r==n/2){
					ans+=a[i].x;
					l++;
				}
				else if(r+1<=n/2){
					ans+=a[i].y;
					r++;
				}
			}
			cout<<ans<<"\n";
//			cout<<l<<" "<<r<<<<"\n";
		}
		else{
			sum=0;
			dfs(1,0,0,0,0);
			cout<<sum<<"\n";
		}
	}
	return 0;
}
