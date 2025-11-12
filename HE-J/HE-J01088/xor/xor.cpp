#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N],f[N],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int subB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) subB=0;
	}
	if(subB){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++,i++;
				}
				if(a[i]==0) ans++;
			}
		}else{
			for(int i=1;i<=n;i++) ans+=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int xr=0,p=n+1;
		for(int j=i;j<=n;j++){
			xr^=a[j];
			if(xr==k){
				p=j;
				break;
			}
		}
		f[i]=p;
	}
	for(int i=1;i<=n;i++){
		int flag=1;
		for(int j=i+1;j<=n;j++){
			if(f[j]<=f[i]){
				flag=0;
				break;
			}
		}
		if(flag&&f[i]<=n){
			ans++;
			i=f[i];
		}
	}
	cout<<ans;
	return 0;
}

