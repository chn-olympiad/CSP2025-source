#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,c[505],b[505],dp[505];
char s[505];
void kfc(long long i,long long sum){
	if(i==n+1){
		if(sum>=m){
			/*for(long long j=1;j<=n;j++){
				cout<<dp[j]<<" ";
			}
			cout<<endl;*/
			ans+=1;
		}
		return;
	}
	for(long long j=1;j<=n;j++){
		if(!b[j]){
			b[j]=1;
			if(s[i]=='0' || sum>=c[j]) kfc(i+1,sum);
			else kfc(i+1,sum+1);
			b[j]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>s[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		kfc(1,0);
		cout<<ans;
	}
	return 0;
}

