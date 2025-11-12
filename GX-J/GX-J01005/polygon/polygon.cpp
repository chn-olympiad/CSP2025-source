#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,sum;
int a[N];


void solve(){
	int b=0,c=a[1]+a[2]+a[3];
	for(int i=1;i<=n;i++)b=max(b,a[i]);
	if(c>2*b)cout<<1;
	else cout<<0;
	
	
}
void solve1()
{
	int x=((n+1)*n)/2;
	for(int i=3;i<=n;i++){
		int y=((i+1)*i)/2,z=y*(n-i);
		sum+=x/z;
	}
	cout<<sum%998244353;
	
}










int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3)solve();
	else if(a[n]==1)solve1(); 
	else cout<<0;
	
	
	return 0;
}
