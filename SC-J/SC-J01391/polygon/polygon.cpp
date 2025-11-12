#include<bits/stdc++.h>
using namespace std;
const int mx = 998244353;

int n, a[50004], f[50004];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	if(n == 3){
		if(sqrt((a[1]*a[1])+(a[2]*a[2])) == a[3]){
			cout<<1;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		f[i] = f[i-1]+a[i];	
	//	cout<<f[i]<<" ";	
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
		//	cout<<1<<" ";
			if((f[j] - f[i-1]) > (a[j]*2)){
				ans++;
				ans%=mx;
			//	cout<<f[j] - f[i-1]<<" ";
			//	cout<<i<<" "<<j<<endl;
			}
		}
	}
	
	cout<<ans;

	return 0;
} 