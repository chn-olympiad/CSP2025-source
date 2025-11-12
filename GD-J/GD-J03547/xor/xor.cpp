#include<bits/stdc++.h>
using namespace std;
long long n,k,a[555555],ans,zh1[555555],zh2[555555];
bool f[555555];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k){
			ans++; 
			f[i]=1;
		}
		zh1[i]=a[i];
	}
	for(int j=2;j<=n;j++){
		for(int i=j;i<=n;i++){
		 zh2[i]=a[i]^zh1[i-1];
			bool s=1; 
			for(int p=i-j+1;p<=i;p++){
				if(f[p]){
					s=0;break;
				}	
			}
			if(zh2[i]==k&&s){
				ans++;
				for(int p=i-j+1;p<=i;p++){
					f[p]=1;
				}
			}
		}
		for(int i=j;i<=n;i++){
			zh1[i]=zh2[i];
		}
	}
	cout << ans;
	
	
	
	return 0;
}
