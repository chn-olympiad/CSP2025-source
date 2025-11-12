#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100,L=5e6+10,P=1e9+7,M=998244353;
int n,q,ls[N],rs[N],lt[N],rt[N],ps1[N],ps2[N],pt1[N],pt2[N];
string s1[N],s2[N],t1[N],t2[N];
bool is_caseB()
{
//	cout<<"yes"<<endl;
	for(int i=1;i<=n;i++)
	{
		int cnt1=0,cnt2=0;
		for(int j=1;j<s1[i].length();j++)
		{
			char c1=s1[i][j];
			if(c1=='b')cnt1++,ps1[i]=j;
			if((c1!='a'&&c1!='b')||cnt1>1)return false;
			char c2=s2[i][j];
			if(c2=='b')cnt2++,ps2[i]=j;
			if((c2!='a'&&c2!='b')||cnt2>1)return false;
		}
	}	
	for(int i=1;i<=q;i++)
	{
		int cnt1=0,cnt2=0;
		for(int j=1;j<t1[i].length();j++)
		{
			char c1=t1[i][j];
			if(c1=='b')cnt1++,pt1[i]=j;
			if((c1!='a'&&c1!='b')||cnt1>1)return false;
			char c2=t2[i][j];
			if(c2=='b')cnt2++,pt2[i]=j;
			if((c2!='a'&&c2!='b')||cnt2>1)return false;
		}
	}
//	cout<<"yes"<<endl;
	return true;
}
void caseB()
{
//	cout<<"Yes"<<endl;
	for(int i=1;i<=q;i++)
	{
		int res=0;
		for(int j=1;j<=n;j++)
		{
			if(ps1[j]-ps2[j]==pt1[i]-pt2[i]&&ps1[j]<=pt1[i]&&
			s2[j].length()-1-ps2[j]<=t2[i].length()-1-pt2[i])
				res++;
		}
		cout<<res<<endl;
	}
}
void caseA()
{
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<t1[i].length();j++)
		{
			if(!lt[i]&&t1[i][j]!=t2[i][j])
				lt[i]=j;
			if(t1[i][j]!=t2[i][j])
				rt[i]=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<s1[i].length();j++)
		{
			if(!ls[i]&&s1[i][j]!=s2[i][j])
				ls[i]=j;
			if(s1[i][j]!=s2[i][j])
				rs[i]=j;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int res=0;
		for(int j=1;j<=n;j++)
		{
			if(rt[i]-lt[i]==rs[j]-ls[j]&&
			ls[j]<=lt[i]&&
			s1[j].length()-rs[j]<=t1[i].length()-rt[i])
			{
				int ps=1,pt=lt[i]-ls[j]+1,bj=0;
				for(int k=1;k<s1[j].length();k++)
				{
					int jj=ps+k-1,ii=pt+k-1;
					if(s1[j][jj]!=t1[i][ii]||s2[j][jj]!=t2[i][ii])
					{
						bj=1;break;
					}	
				}
				if(!bj)res++;
			}
		}
		cout<<res<<endl;
	}
}
void input()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i],s1[i]=" "+s1[i],s2[i]=" "+s2[i];
	for(int i=1;i<=q;i++)
		cin>>t1[i]>>t2[i],t1[i]=" "+t1[i],t2[i]=" "+t2[i];
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	input();
	if(is_caseB())caseB();
	else caseA();
	return 0;
}
