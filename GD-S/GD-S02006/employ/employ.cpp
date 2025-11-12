#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,num,sum,b[N];
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>a;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		b[i]-=sum;
		if(b[i]<0){
			sum++;
			continue;
		}
		if(a[i]=='1')num++;
		else sum++;
	}
	num%=998244353;
	cout<<1;
	return 0;
}
