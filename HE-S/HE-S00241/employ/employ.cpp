#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[510],b=0,sum=0;
	unsigned long long ans,c[510];
	string s;
	cin>>n>>m>>s;
	sum=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=a[i]-b;
		if(a[i]<=0){
			sum--;
			b++;
		}
	}
	c[0]=1;
	for(int i=1;i<=sum;i++){
		c[i]=i*c[i-1];
	}
	ans=c[sum]%998244353;
	cout<<ans;
	return 0;
}
