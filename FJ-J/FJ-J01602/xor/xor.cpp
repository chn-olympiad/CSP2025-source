#include<bits/stdc++.h>
using namespace std;
const int MAX=5*1e5+5;
int n,sum[MAX],a[MAX],k;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	int l=1,ans=0;
	for (int i=1;i<=n;i++) {
		int a=sum[i],b=sum[l-1];
		if ((a^b)==k){
			ans++;
			l=i+1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
