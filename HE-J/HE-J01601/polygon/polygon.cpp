#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long a[5005],n,maxx,yh[5005][5005],ans; 
bool cnt(int x){
	int ans=0;
	while(x){
		if(x%2==1) ans++;
		x/=2;
	}
	return ans>=3;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		yh[0][0]=1;
		for(int i=1;i<=n;i++){
			yh[i][0]=1;
			yh[i][i]=1;
			for(int j=1;j<i;j++){
				yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
			}
		}
		for(int j=3;j<=n;j++){
			ans+=yh[n][j];
			ans%=mod;
		}
		cout << ans;
		return 0;
	}
	else{
		for(int i=1;i<pow(2,n);i++){
			if(cnt(i)){
				long long sum=0,big=0;
				for(int j=0;j<n;j++){
					if(i&(1<<j)){
						sum+=a[j+1];
						big=max(big,a[j+1]);
					}
				}
				if(sum>2*big){
					ans++;
					ans%=mod;
				}
			}
		}
		cout << ans;
		return 0;
	}
} 
