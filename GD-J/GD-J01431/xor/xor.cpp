#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],s,f[500005];
bool fa=1,fb=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fa=0;
		if(a[i]>1) fb=0;
	}
	if(n<=100){
		for(int i=1;i<=n;i++)
			b[i]=b[i-1]^a[i];
		for(int i=1;i<=n;i++){
			f[i]=f[i-1];
			if(a[i]==k) f[i]++,s=i;
			else{
				for(int j=s;j<i;j++){
					int t=b[j]^b[i];
					if(t==k){
						if(f[j]+1>=f[i]) s=i;
						f[i]=max(f[i],f[j]+1);
					}
				}
			}
		}
		cout<<f[n];
	}
	else{
		if(fa){
			cout<<n/2;
			return 0;
		}
		if(fb){
			if(k==0){
				int ans=0;
				for(int i=1;i<=n;i++){
					if(a[i]==0) ans++;
					if(a[i]==1&&a[i-1]==1) ans++;
				}
				cout<<ans;
			}
			else{
				int ans=0;
				for(int i=2;i<=n;i++)
					if(a[i]!=a[i-1]) ans++,i++;
				cout<<ans;
			}
			return 0;
		}
		for(int i=1;i<=n;i++)
			b[i]=b[i-1]^a[i];
		for(int i=1;i<=n;i++){
			f[i]=f[i-1];
			if(a[i]==k) f[i]++,s=i;
			else{
				for(int j=s;j<i;j++){
					int t=b[j]^b[i];
					if(t==k){
						if(f[j]+1>=f[i]) s=i;
						f[i]=max(f[i],f[j]+1);
					}
				}
			}
		}
		cout<<f[n];
	}
	return 0;
}
