#include<bits/stdc++.h>
using namespace std;
long long t,num,d,e;
long long maxn=1e9+10;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	long long n,a[maxn],b[maxn],c[maxn];
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			d=max(b[i],c[i]);
			e=max(d,a[i]);
			num+=e;}
			cout<<num;
	}
	return 0;
}
