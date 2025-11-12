#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		cnt=a[i];
		for(long long j=i;j<=n;j++){
			cnt=cnt^a[j];
			if(cnt==k){
				ans++;
				cnt=0;
				cout<<i<<" "<<j<<endl;
				i=j;
			}
		}
	}
	cout<<ans+1;
	return 0;
}

