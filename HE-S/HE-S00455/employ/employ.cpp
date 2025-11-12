#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100010],b[100010],c[100010],x,z,m;
int s1[100100],s2[100100],s3[100100];
char o[1000000];
long long ans=1;
const int M=998244353;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>o;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=1000000;i++) {
		if(o[i]=='1') x++;
		if(o[i]=='0' )z++;
	}
	for(int i=0;i<n;i++){
		ans%=M;
		ans*=(x-i);
	}
	cout<<ans;
	return 0;
}
