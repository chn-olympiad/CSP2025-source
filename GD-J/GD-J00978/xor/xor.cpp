#include<bits/stdc++.h>
using namespace std;

long long a[500005],ps[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ps[i]=ps[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<'\n';
		for(int j=0;j<=n-i;j++){
			if((ps[i+j]^ps[i-1])==k){
				cout<<i<<' '<<i+j<<'\n';
				i=i+j;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
