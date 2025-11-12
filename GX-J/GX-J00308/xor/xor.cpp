#include <bits/stdc++.h>
using namespace std;
int n,k,num2,ans;
int s[500010];
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		if(s[i]==k) ans++;
	}
	for(int i=1;i<=n;i++){ 
		num2=s[i];
		for(int j=i+1;j<=n;j++){
			num2=num2 & s[j];
			if(num2==k){
				ans++;
			}	
		}
	}
	cout<<ans;
	return 0;
}
