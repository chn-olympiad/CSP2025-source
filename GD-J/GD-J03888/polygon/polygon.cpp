#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);
	cout<<n+1; 
	return 0;
}
