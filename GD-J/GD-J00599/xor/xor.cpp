#include<algorithm>
#include<iostream>
using namespace std;
int n,k;
long long int ans=0;
int a[500005],f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(f[i]==k){
			ans++;
		}else{
			for(int j=i;j<=n;j++){
				if((a[i-1]|a[j])==k&&f[j]!=k&&i!=j){
					ans++;
					i=j;
					break;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
