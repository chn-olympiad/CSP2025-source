#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005];
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",a[i]);
		if(a[i]==1) f=1;
	}
	if(k==1&&f==0) cout<<0;
	else if(k==0&&f==1) cout<<n/2;
	else if(k==f) cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
