#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 998244353
int a[5005];
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,a,b,c;
	cin>>n;
	cin>>a>>b>>c;
	if(a+b>c*2)ans++;
	if(a+c>b*2)ans++;
	if(b+c>a*2)ans++;
	cout<<ans<<endl;
	return 0;
}
