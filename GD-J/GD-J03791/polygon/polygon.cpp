#include<bits/stdc++.h>
using namespace std;
int n,k=3,p;
long long ans,MOD=998244353;
int a[5005],b[1000005],f[1000005]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			p=1;
		}
	}
	if(p==0){
		long long w=1,v=1,sum=(1+n+n*(n+1)/2)%MOD;
		for(int i=3;i<=n/2;i++){
			w=1,v=1;
			for(int j=n;j>=n-i+1;j--){
				w=(w*j)%MOD;
			}
			for(int j=i;j>=1;j--){
				v=(v*j)%MOD;
			}
			sum+=((w/v*2)%MOD);
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+1+n);
	f[1]=1,f[2]=1,f[3]=1;
	b[1]=a[1],b[2]=a[2],b[3]=a[1]+a[2];
	if(b[3]>a[3]){
		ans++;
	}
	for(int i=3;i<n;i++){
		int m=k,c=1,p=1,l=1;
		for(int j=m;j>=1;j--){
			if(b[j]+a[i]<=b[m]){
				p=j+1;
				break;
			}
		}
		for(int j=p;j<=m;j++){
			k++;
			b[c+m]=b[j]+a[i];
			f[c+m]=f[j];
			while(b[j]+a[i]==b[l]+a[i+1]&&l!=j&&l<=p){
				f[c+m]++;
				l++;
			}
			c++;
		}
		for(int j=k;j>=1;j--){
			if(b[j]>a[i+1]){
				ans=(ans+f[j])%MOD;
			}
		}
	}
	cout<<ans;
	return 0;
}

