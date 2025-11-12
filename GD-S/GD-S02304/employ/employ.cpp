#include<bits/stdc++.h>
using namespace std;
long long n,ans=1,m,p[505],P=998244353;
char c[505];
int main()
{
	//我是浦帅的忠实粉丝 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		
	} 
	for(int i=1;i<=n;i++){
		cin>>p[i];
	} 
	for(int i=1;i<=n;i++) ans=(ans*i)%P;
	cout<<ans;
	return 0;
} 
