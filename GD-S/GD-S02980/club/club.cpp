#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n;
ll A[N][5],B[N];
ll ans=-1;
ll cnt[5];
ll maxA[N];
ll s[N];
void dfs(ll x,ll sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(sum+s[x]<ans){
		return;
	}
	for(int j=1;j<=3;j++){
		if(cnt[j]<n/2){
			cnt[j]++;
			dfs(x+1,sum+A[x][j]);
			cnt[j]--;
		}
	}
}
bool checkA(){
	for(int i=1;i<=n;i++)
		if(A[i][2]!=0||A[i][3]!=0)
			return false;
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>A[i][j],maxA[i]=max(maxA[i],A[i][j]);
		if(checkA()){
			for(int i=1;i<=n;i++)
				B[i]=A[i][1];
			sort(B+1,B+n+1);
			for(int i=n;i>n/2;i--)
				ans+=B[i];
			cout<<ans<<endl;
			continue;
		}
		s[n+1]=0;
		for(int i=n;i>=1;i--)
			s[i]=s[i+1]+maxA[i];
		dfs(1,0);
		cout<<ans<<endl;
	} 
	return 0;
} 
