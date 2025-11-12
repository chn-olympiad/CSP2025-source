#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
#define f(n) for(int i=1;i<=n;i++)
queue<int> wz;
int n,q,pi[10000011],lth[200001];
string rep[200001],inst[200001],ql,qr;
void kmp(string x)
{
	f(x.length())pi[i-1]=0;
	int ls;
	f(x.length()-1)
	{
		ls=pi[i-1];
		while(x[ls]!=x[i]&&ls!=0)ls=pi[ls-1];
		if(x[ls]==x[i])pi[i]=ls+1;
	}
}
bool stt[5000001],stw[5000001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	f(n)
	{
		cin>>rep[i]>>inst[i];
		lth[i]=rep[i].length();
	}
	string qql;
	ll ans;int wzl,wzr;
	while(q--)
	{
		ans=0;
		cin>>ql>>qr;
		for(int i=0;i<ql.length()&&ql[i]==qr[i];i++)stt[i]=true;
		for(int i=ql.length()-1;i>=0&&ql[i]==qr[i];i--)stw[i]=true;
		f(n)
		{
			qql.clear();
			qql=rep[i];qql+="#";qql+=ql;
			kmp(qql);
			for(int j=1;j<=qql.length();j++)if(lth[i]==pi[j])wz.push(j);
			qql.clear();
			qql=inst[i];qql+="#";qql+=qr;
			kmp(qql);
			while(!wz.empty())
			{
				wzr=wz.front()-lth[i]-1;
				wzl=wz.front()-(lth[i]<<1);
		//		cout<<wz.front()<<" "<<wzl<<" "<<wzr<<" "<<ans<<endl;
				if(pi[wz.front()]==lth[i]&&wzl==0&&wzr==ql.length()-1)ans++;
				else if(pi[wz.front()]==lth[i]&&stt[wzl-1]&&stw[wzr+1])ans++;
				wz.pop();
			}
			//cout<<endl;
		}
		cout<<ans<<"\n";
		f(ql.length())
		{
			stt[i-1]=false;
			stw[i-1]=false;
		}
	}
	return 0;
}


