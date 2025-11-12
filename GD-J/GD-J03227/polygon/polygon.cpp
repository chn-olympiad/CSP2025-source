#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int dp[5001];
int pre[5001];
int const Mod=998244353;
long long ans,cnt;
bool cmp(int a,int b){ return a<=b;}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int maxx;
	for(int i=3;i<=n;i++){//终点 
		maxx=a[i];
		int l=1,r=2;//区间长 
		while(l<i&&r<i){
			if(pre[r]-pre[l-1]>maxx){
				cnt+=(r-l)*(i-r);
				r++;
				l=1;
			}
			else{
				r++;
				l=1;
			}
		}
	}
	cout<<cnt;
	return 0;
 } 
