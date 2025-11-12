#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct D{
	long long i=0;
	long long p=0;
	long long q=0;
}d[20000],dp[20000];
int t=0;
long long n=0;
long long a[10];
long long maxn=0;
bool cmp(D dt,D dr){
	if(dt.p>=dr.p) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	long long it=0,qt=0;
	for(int i=1;i<=t;i++){
		it=0;
		qt=0;
		cin>>n;
		for(int y=1;y<=n;y++){
			cin>>d[y].i>>d[y].p>>d[y].q;
			it+=d[y].i;
			qt+=d[y].q;
		}
		if(n==2){
			maxn=max(maxn,d[1].i+d[2].p);
			maxn=max(maxn,d[1].i+d[2].q);
			maxn=max(maxn,d[1].p+d[2].i);
			maxn=max(maxn,d[1].p+d[2].q);
			maxn=max(maxn,d[1].q+d[2].i);
			maxn=max(maxn,d[1].q+d[2].p);
			a[i]=maxn;
			maxn=0;
			continue;
		}
		else if(it==0&&qt==0){
			sort(d+1,d+n+1,cmp);
			for(int y=1;y<=n/2;y++){
				maxn+=d[y].p;
			}
			a[i]=maxn;
			maxn=0;
			continue;
		}
		else{
			dp[1].i=d[1].i;
			dp[1].p=d[1].p;
			dp[1].q=d[1].q;
			for(int y=2;y<=n;y++){
				dp[y].i=max(dp[y-1].p+d[y].i,dp[y-1].q+d[y].i);
				dp[y].p=max(dp[y-1].i+d[y].p,dp[y-1].q+d[y].p);
				dp[y].q=max(dp[y-1].i+d[y].q,dp[y-1].p+d[y].q);
			}
			maxn=max(dp[n].i,dp[n].p);
			maxn=max(maxn,dp[n].q);
			a[i]=maxn;
			maxn=0;
			continue;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<a[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
