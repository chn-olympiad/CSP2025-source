#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	fill(a+1,a+500009,2e9);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k<=1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k) ans++;
			else if(a[i]==a[i+1]) ans++,i++;
//			cout<<i<<' '<<ans<<'\n';
		}
		cout<<ans;
	}
	cout<<n/2;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
