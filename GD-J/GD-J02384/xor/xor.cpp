#include <bits/stdc++.h>
using namespace std;
long long n,k;
bool f;
long long sum=0;
long long u=0;
const long long N=500000+10;
long long dp[N]={0};
long long a[N]={0};
bool b[N]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0){
			n--;
			i--;
			u++;
		}else if(a[i]>1)f=false;
	}
	if(k==0){
		cout << u;
		return 0;
	}
	if(f){
		cout << n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=(dp[i-1] xor a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int l=1;i+l-1<=n;l++){
			long long r=l+i-1;
			bool g=0;
			for(int j=l;j<=r;j++){
				if(b[j]==true){
					g=true;
					break;
				}
			}
			if(g)continue;
			long long h=(dp[r] xor dp[l-1]);
			if(h==k){
				sum++;
				for(int j=l;j<=r;j++)b[j]=true;
			}
		}
	}
	cout << sum;
	return 0;
}
