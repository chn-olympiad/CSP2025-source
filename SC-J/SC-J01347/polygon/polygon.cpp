#include<bits/stdc++.h>
using namespace std;
const long long M=998224353;
long long a[5100],b[5100];
long long tt[5100];
long long zh(int n,int m){
	long long p=1,q=1;
	for(int i=n-m+1;i<=n;i++){
		p*=i;
		p%=M;
	}
	for(int i=1;i<=m;i++){
		q*=i;
		q%=M;
	}
	return p/q;
}
bool cmp(int a,int b){
	return a>b;
}
int n;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
		if(a[i]!=a[i+1])tt[a[i+1]]=i;
	}
	tt[a[1]]=0;
	for(int i=n;i>=1;i--){
		long long t=b[i-1];
		int d=0,j=i-1,r=i-1;
		while(t>a[i]){
			ans+=zh(r,d);
			ans%=M;
			while(t-a[j]<=a[i]&&j>=1){
				j=tt[a[j]];
				r=tt[a[j]];
				d=0;
			}
			t-=a[j--];
			d++;
		}
	}
	cout<<ans;
	return 0;
} 