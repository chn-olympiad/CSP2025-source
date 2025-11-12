#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int num[N];
int dp[2001];
const int MAXN=1e5+1;
const int mod=998244353;
int tj[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int R;
	cin>>R;
	if(R<3){
		cout<<0;
		return 0;
	}

	for(int i=1;i<=R;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+R);
	if(R==3){
		if(num[R]>=num[1]+num[2]){
			cout<<0;
			return 0;
		}
		else cout<<1;
	}
	long long w=0;
	for(int i=3;i<=R;i++){
		long long x=1;
		for(int j=R;j>=R-i+1;j--){
			x*=j;
			x%=mod;
		}
		int l=1;
		for(int j=1;j<=i;j++){
			l*=j;
			l%=mod;
		}
		w+=x/l;
		w%=mod;
	}
	cout<<w;
	return 0;
}