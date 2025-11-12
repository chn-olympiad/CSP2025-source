#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],x[500005],cnt=0,f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i]^x[i-1];
	}
	for(int i=1;i<=n;i++){
		f=i;
		for(int j=i;j<=n;j++){
			long long s=x[i-1]^x[j];
			if(s==k){
				cnt++;
				f=j+1;
				break;
			}
		}
		i=f;
	}
	cout<<cnt;
	return 0;
}
