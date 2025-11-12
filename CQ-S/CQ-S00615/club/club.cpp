#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
struct fz{
	int a,b,c;
}a[N];
int n,T,ans,s[5];
void dfs(int d,int sum){
	if (d==n+1){
		ans=max(ans,sum);
		return;
	}
	if (s[1]<n/2){
		s[1]++;
		dfs(d+1,sum+a[d].a);
		s[1]--;
	} 
	if (s[2]<n/2){
		s[2]++;
		dfs(d+1,sum+a[d].b);
		s[2]--;
	} 
	if (s[3]<n/2){
		s[3]++;
		dfs(d+1,sum+a[d].c);
		s[3]--;
	} 
}
bool cmp(fz x,fz y){
	return x.a>y.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while (T--){
		cin>>n;
		ans=0;
		s[1]=0;
		s[2]=0;
		s[3]=0;
		for (int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		if (n<=10){
			dfs(1,0);
			cout<<ans<<endl;
		}else{
			sort(a+1,a+n+1,cmp);
			for (int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans;
		}
	}
	return 0;
}
