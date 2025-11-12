#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=2e5+6;
string as1[N],as2[N],at1[N],at2[N];
string bs1[N],bs2[N],bt1[N],bt2[N];
ll n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>as1[i]>>as2[i];
		ll top=0;
		for(int j=0;j<as1[i].size();j++)
		{
			ll cnt=0;
			if(as1[i][j]!=as2[i][j])
			{
				if(cnt==0)
				if(cnt%2==1)
				{
					bs1[i]+=as1[i][j];
					bs2[i]+=as2[i][j];
				}
				
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>at1[i]>>at2[i];
		ll top=0;
		for(int j=0;j<at1[i].size();j++)
		{
			if(at1[i][j]!=at2[i][j])
			{
				bt1[i]+=at1[i][j];
				bt2[i]+=at2[i][j];
			}
		}
		// ========== answer ========== //
		ll ans=0;
		for(int k=1;k<=n;k++)
		{
			if(bt1[i][0]!=bs1[k][0] || bt2[i][0]!=bs2[k][0])
				continue;
			else
			{
				bool flag=1;
				for(int j=1;j<bt1[i].size();j++)
				{
					if(bt1[i][j]!=bs1[k][j] || bt2[i][j]!=bs2[k][j])
					{
						flag=0;
						break;
					}
				}
				if(flag)
					ans++;
			}
		}
		cout<<ans<<endl;
		
		// ============================ //
	}
	// ============ debug ============== //
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<bs1[i].size();j++)
//			cout<<bs1[i][j];
//		cout<<' ';
//		for(int j=0;j<bs2[i].size();j++)
//			cout<<bs2[i][j];
//		cout<<endl;
//	}
//	for(int i=1;i<=q;i++)
//	{
//		for(int j=0;j<bt1[i].size();j++)
//			cout<<bt1[i][j];
//		cout<<' ';
//		for(int j=0;j<bt2[i].size();j++)
//			cout<<bt2[i][j];
//		cout<<endl;
//	}
	
	// ================================= //
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
	
	
	
	// XHX love WZL!!!
}

