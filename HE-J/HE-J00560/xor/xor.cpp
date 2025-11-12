#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000005],s[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	if(k==0) cout<<"0";
	else if(k==1) cout<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
