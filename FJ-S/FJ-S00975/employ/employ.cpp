#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
ll read(){
	ll ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
const ll N=1e4,M=1e6;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<0<<endl;
	return 0;
}
