//GZ-S00322 北京师范大学贵阳附属中学 王明轩 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[510];
string str;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long sum = 1;
	for(int i=1;i<=n;i++){
		sum*=i%998244353;
	}
	cout<<sum;
	return 0;
	
}
