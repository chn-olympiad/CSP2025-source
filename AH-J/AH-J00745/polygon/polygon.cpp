#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005],s[5005],f[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3&&a[1]+a[2]>a[3]&&a[3]+a[1]>a[2]&&a[3]+a[2]>a[1]){
		cout<<1;
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++){
			for(int k=j;k<i;k++){
				if(s[k]-s[k-j]>a[i]){
					f[i]++;
				}
			}
		}
		f[i]+=f[i-1];
	}
	cout<<f[n];
	return 0;
}
