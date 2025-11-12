#include<bits/stdc++.h>
#include<string>
using namespace std;
int c[505];
int n,m;
string s;
void A()
{
	int k=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)k++;
	}
	if(m<n-k){
		int sum=1;
		for(int i=1;i<=n;i++)
		{
			sum*=i;
			sum%=998244353;
		}
		cout<<sum<<endl;
	}
	else
	{
		int sum=1;
		for(int i=1;i<=m-(n-k);i++)
		{
			sum*=i;
			sum%=998244353;
		}
		cout<<sum<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f1=true;
	cin>>s;
	int l=s.length();
	for(int i=0;i<=l-1;i++)
    {
		if(s[i]!='1')f1=false;
    }
    for(int i=1;i<=n;i++){
		cin>>c[i];
	}
    if(f1==true)A();
	return 0;
}
