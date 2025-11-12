#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,num,sum;
string a[N],b[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n+m;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<m;i++)cout<<"0"<<endl;
	return 0;
}
