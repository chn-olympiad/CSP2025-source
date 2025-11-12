#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N],maxn=-1;
int n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(k==0 && a[i]==0){
			ans++;
		}
	}
	if(k==0){
		cout << ans;
		return 0;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		for(int t=1;t<=n-i;t++){
			ans=0;
			sum=0;
			for(int j=t;j<=n;j++){
				sum+=a[j];
				if(j%i==0){
					if(sum%k==0 && sum!=0){
						ans++;
						sum=0;
					}
				}
			}
			maxn=max(ans,maxn);
		}
	}
	cout << maxn;
    return 0;
}
