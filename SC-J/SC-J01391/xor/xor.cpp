#include<bits/stdc++.h>
using namespace std;

long long n, k, a[500002], f[500002], vis[500002];
long long solve(long long a, long long b){
	long long c = 0, ans = 0;
	while(a != 0 || b != 0){
		if((a % 2) != (b % 2)){
			ans+=pow(2,c);
			if(a == 1){
				a = 0;
			}
			if(b == 1){
				b = 0;
			}
		}else{
			if(a == 1){
				a = 0;
			}
			if(b == 1){
				b = 0;
			}
		}
		a/=2;
		b/=2;
		c++;
	}
//	cout<<ans<<endl;
	return ans;
}

int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
		f[i] = solve(f[i-1],a[i]);
	}

	for(long long i = 1;i <= n;i++){
		for(long long j = i;j <= n;j++){
			if(abs(f[j] - f[i-1]) == k){
				int b = 1;
				for(long long k = i;k <= j;k++){
					if(vis[k] == 1){
						b = 0;
					}
				}
			//cout<<i<<" "<<j<<endl;
				if(b == 1){
					ans++;
					for(long long k = i;k <= j;k++){
						vis[k] = 1;
					}					
				}			
			}
		}
	}
	
	cout<<ans;
	return 0;
} 