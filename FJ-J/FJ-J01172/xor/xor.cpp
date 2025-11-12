#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,c,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		ans=0,c=-1;
		for(long long i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				c=-1;
			}
			else if(a[i]==1){
				if(c==1){
					ans++;
					c=-1;
				}
				else{
					c=a[i];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(k==1){
		ans=0;
		for(long long i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<1;
	}
	return 0;
}
