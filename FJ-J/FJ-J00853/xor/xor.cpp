#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],f[500001],ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++) if(a[i]==0) ans++;
		cout<<ans;
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			int m=1;
			while(m<=n-i){
				for(int j=1;j<=i;j++){
				    if(j==1) cnt=a[j];
				    else cnt^=a[j];
			    }
			    if(cnt==k) ans++;
			    m++;
			}
		}
		cout<<ans-1;
	}
	return 0;
}
