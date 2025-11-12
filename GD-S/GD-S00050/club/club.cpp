#include<bits/stdc++.h>
using namespace std;
int t, n, a[100010][4], ans, f, f2, f3, s[100010];
void dfs(int step, int on, int tw, int th, int sum){
	if(s[n]-s[step-1]+sum<ans){
		return ;
	}
	if(on>n/2){
		return ;
	}
	if(tw>n/2){
		return ;
	}
	if(th>n/2){
		return ;
	}
	if(step>n){
		ans=max(ans, sum);
		return ;
	}
 	dfs(step+1, on+1, tw, th, sum+a[step][1]);
	dfs(step+1, on, tw+1, th, sum+a[step][2]);
	dfs(step+1, on, tw, th+1, sum+a[step][3]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++){
			s[i]=0;
		}
		ans=0;
		for(int i=1; i<=n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 || a[i][3]!=0){
				f=1;
			}
			if(a[i][1]!=0 || a[i][2]!=0){
				f2=1;
			}
			if(a[i][1]!=0 || a[i][3]!=0){
				f3=1;
			}
			s[i]=s[i-1]+max(a[i][1], max(a[i][2], a[i][3]));
		}
		if(f==0){
			int b[100010];
			for(int i=1; i<=n; i++){
				b[i]=a[i][1];
			}
			sort(b+1, b+n+1);
			for(int i=n; i>=n/2; i--){
				ans+=b[i];
			}
			cout<<ans;
			continue;
		}
		if(f2==0){
			int b[100010];
			for(int i=1; i<=n; i++){
				b[i]=a[i][2];
			}
			sort(b+1, b+n+1);
			for(int i=n; i>=n/2; i--){
				ans+=b[i];
			}
			cout<<ans;
			continue;
		}
		if(f3==0){
			int b[100010];
			for(int i=1; i<=n; i++){
				b[i]=a[i][3];
			}
			sort(b+1, b+n+1);
			for(int i=n; i>=n/2; i--){
				ans+=b[i];
			}
			cout<<ans;
			continue;
		}
		dfs(1, 0, 0, 0, 0);
		cout<<ans<<endl;
	}
	return 0;
}

