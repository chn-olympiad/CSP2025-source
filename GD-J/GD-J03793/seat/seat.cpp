#include<bits/stdc++.h>
using namespace std;
long long a[100005],n,m,s,t,k,b,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--) if(a[i]==s) t=k-i+1;
	for(int i=1;i<=m;i++) if(t<=i*n) {b=i,p=t-(i-1)*n;break;}
	if(b%2==0) cout<<b<<" "<<n-p+1;
	else cout<<b<<" "<<p;
	return 0;
} 
