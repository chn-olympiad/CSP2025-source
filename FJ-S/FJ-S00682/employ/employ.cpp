#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
string o;
int a[505],b[505],q=998244353;
int d(int x,int y){
	long long z=1;
	for(int i=x;i<=y;i++)z=(z*i+q)%q;
	return z;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>o;
	for(int i=1; i<=n; i++)a[i]=a[i-1]+o[i]-'0';
	for(int i=1; i<=n; i++)cin>>b[i];
	sort(b+1,b+1+n);
	for(int i=1; i<=n; i++)while(a[i]+b[k]<=i&&k<=n)b[k]=i,k++;
	k--;//if(a[n]==n)
	cout<<d(2,k);
}
