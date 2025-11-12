#include<bits/stdc++.h>
using namespace std;
long long a[100005][5],c[5],ans,cnt[100005];
int n;
void dfs(int k,long long sum){
	if(k > n){
		ans = max(ans,sum);
		return;
	}
	for(int i = 1; i <= 3; i++){
		if(c[i] < n/2){
			c[i]++;
			dfs(k+1,sum + a[k][i]);
			c[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int tmp = 1;
		ans = 0;
		c[1]=c[2]=c[3]=0;
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				tmp = 0;
			}
		}
		if(tmp){
			for(int i = 1; i <= n; i++){
				cnt[i] = a[i][1];
			}
			sort(cnt+1,cnt+1+n,greater<long long>());
			int sum = 0;
			for(int i = 1; i <= n/2; i++) sum += cnt[i];
			cout<<sum<<endl;
			continue;
		}
		else if(n == 2){
			cout<<max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),max(a[1][2]+a[2][1],a[1][2]+a[2][3])),max(a[1][3]+a[2][1],a[1][3]+a[2][2]))<<endl;
			continue;
		}
		else{
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
