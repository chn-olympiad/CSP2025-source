#include <bits/stdc++.h>
using namespace std;
long long a[100006][4],n;
long long m[100006];
long long dfs(long long i,long long cur,long long a1,long long a2,long long a3){
	i++;
	if (i>n) return cur;
	int ans1=0,ans2=0,ans3=0;
	if (a1<n/2) ans1=dfs(i,cur+a[i][1],a1+1,a2,a3);
	if (a2<n/2) ans2=dfs(i,cur+a[i][2],a1,a2+1,a3);
	if (a3<n/2) ans3=dfs(i,cur+a[i][3],a1,a2,a3+1);
	int ans=max(ans1,ans2);
	ans=max(ans,ans3);
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		if (n>=100000){
			for (long long i=1;i<=n;i++){
				long long x,y;
				cin >> m[i] >> x >> y;
			}
			sort(m+1,m+n+1);
			long long l=0;
			for (long long i=n;i>n/2;i++) l+=m[i];
			cout << l << endl;
		}else{
			for (long long i=1;i<=n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
			cout << dfs(0,0,0,0,0) << endl;
		}
	}
	return 0;
} 
