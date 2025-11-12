#include <bits/stdc++.h>
using namespace std;
long long a[19999];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			if(cnt==m){
				ans++;
			}
			cnt+=a[j];
		}
		ans=2;
	}
	cout<<ans;
}
