#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int dp[5][50010];
int cnta,cntb,cntc;
long long ans;		
int n;
struct s{
	int cha;
	int hao;
}e[100005];
bool cmp(s a,s b){
	return a.cha>b.cha;
}
void dfs(int x,long long cnt){
	if(x==n){
		ans=max(ans,cnt);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(cnta<n/2){
			cnta++;
			dfs(i,cnt+a[i]);
			cnta--;
		}
		if(cntb<n/2){
			cntb++;
			dfs(i,cnt+b[i]);
			cntb--;
		}
		if(cntc<n/2){
			cntc++;
			dfs(i,cnt+c[i]);
			cntc--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool isA=true,isB=true;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)isA=false;
			if(c[i]!=0)isB=false;
		}
		if(n<=20){
			dfs(0,0);
			cnta=cntb=cntc=0;
		}
		else if(isA){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--){
				ans+=a[i];
			}
		}
		else{
			for(int i=0;i<n;i++){
				e[i].cha=abs(a[i]-b[i]);
				e[i].hao=i; 
			}
			sort(e,e+n,cmp);
			for(int i=0;i<n;i++){
				if(cntb>=n/2||(a[e[i].hao]>b[e[i].hao]&&cnta<n/2)){
					ans+=a[e[i].hao];
					cnta++;
				}
				else if(c[i]>b[i]&&cntc<n/2){
					cntc++;
					ans+=c[e[i].hao];
				}
				else{
					cntb++;
					ans+=b[e[i].hao];
				}
			}
		}
		cout<<ans<<'\n';
	}
} 
