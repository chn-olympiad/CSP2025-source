#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long a[500005],f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	f[0]=0;
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		f[i]=int(a[i]^f[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(int(f[j]^f[i-1])==k){
				ans++;
				j++;
				i=j;
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
