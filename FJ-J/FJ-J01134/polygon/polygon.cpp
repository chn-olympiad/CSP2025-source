#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int er[5010][5010],a[5010],fst[5010],dp[5010][5010],pre[5010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,now=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>1)
		for(int j=a[i]+1;j<=2*a[i];j++){
			if(fst[j-a[i]]==0)break;
			er[i][j]=i-fst[j-a[i]];
//			cout<<i<<' '<<j<<' '<<er[i][j]<<'\n';
		}
		for(int j=0;j<=a[i];j++)er[i][j]=er[i][a[i]+1];
		if(fst[a[i]]==0){
			for(int j=now;j<=a[i];j++){
				fst[j]=i;
			}
			now=a[i]+1;
		}
	}
//	cout<<"dp\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[n];j++){
			dp[i][j]=er[i][j+1]+((j>a[i])?pre[j-a[i]]:pre[1]);
			dp[i][j]%=mod;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
		for(int j=1;j<=a[n];j++)pre[j]+=dp[i][j],pre[j]%=mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ans+=dp[j][a[i]];
			ans%=mod;
		}
	}
	cout<<ans;
//	for(int i=1;i<=a[n];i++)cout<<fst[i]<<' ';
	return 0;
}
//er:取i，多少数对和>=j; 
//fst:某数（若没有则比其大的第一个数）第一次出现的位置 
//dp:i为止,多少集合的数>j 
//10:50 aked
