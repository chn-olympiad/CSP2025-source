#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000010],b[1000010],c[1000010],d[1000010],x,p,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				c[++x]=i;
				d[x]=j;
			}
		}
	}
	for(int i=1;i<=x;i++){
		if(p>=c[i]){
			p=min(d[i],p);
		}else{
			p=d[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
