#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,f[5005][5005];
bool tp1=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i]!=a[i-1]&&i!=1) tp1=false;
	}
	if (tp1){
		f[1][1]=1;
		for (int i = 2;i <= n;i++){
			for (int j = 1;j <= i;j++){
				f[i][j]=f[i-1][j]+f[i-1][j-1];
				f[i][j]%=998244353;
			}
		}
		for (int i = 1;i <= n;i++){
			ans=(ans+f[n][i])%998244353;
		}
		//cout << ans << " ";ans=0;
	}else{
		for (int i = 7;i <= (1<<(n+1))-1;i+=2){
			//cout << "66666666666666666\n";
			int num=0,maxx=-2147483648,s=0;
			for (int j = 1;j <= n;j++){
				if (i&(1<<j)){
					maxx=max(maxx,a[j]);
					num += a[j];s++;
					//cout << a[j] << " ";
				}
			}
			if (s>=3&&num>maxx*2){
				ans++;
				ans%=998244353;
			}
			//cout << "\n" << (s>=3&&num>maxx*2);
			//cout << num << " " << maxx << " " << s << "\n\n";
		}
	}
	cout << ans;
	return 0;
}
