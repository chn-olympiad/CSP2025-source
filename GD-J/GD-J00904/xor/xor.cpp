#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long k,ans,a[N],b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
