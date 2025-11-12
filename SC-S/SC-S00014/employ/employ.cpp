#include<iostream>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int c[n+1];
	double s[n+1];
	for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
	long long a;
	a%=998244353;
	cout<<a<<endl;
	return 0;	
}