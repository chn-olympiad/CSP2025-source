#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MOD = 998244353;
int a[5005],pp3[5005],pp2[5005],n,ans,f[10005],pp1[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i =1;i<=n;i++){
		for(int j =5001;j>=0;j--){
			if(j>a[i]){
				f[min(j+a[i],5001)] += pp3[j]+pp2[j];
				f[min(j+a[i],5001)] %= MOD;
			}
			pp3[min(j+a[i],5001)] += pp3[j];
			pp3[min(j+a[i],5001)] %= MOD;
		}
		for(int j =0;j<=5001;j++){
			pp3[min(j+a[i],5001)] += pp2[j];
		}
		for(int j =1;j<i;j++){
			pp2[min(5001,a[i]+a[j])]++;
		}
	}
	for(int i =3;i<=5001;i++)ans = (ans+f[i])%MOD; 
	cout<<ans;
	return 0;
}
