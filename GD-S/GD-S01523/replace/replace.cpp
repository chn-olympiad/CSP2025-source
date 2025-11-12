#include <bits/stdc++.h>
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
int n,q;
map<string,string> ma;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i = 1; i <= n; i++)
	{
		string s,t;cin>>s>>t;
		ma[s]=t;
	}
	while (q--)
	{
		string s,t;cin>>s>>t;
		int ls=s.size(),lt=t.size();
		s=" "+s,t=" "+t;
		if (ls!=lt){cout<<"0\n";continue;}
		int ans = 0;
		int maxl = 1;
		while (maxl<=lt&&s[maxl]==t[maxl]) maxl++;
		maxl--;
		int minr = lt;
		while (minr>=1&&s[minr]==t[minr]) minr--;
		minr++;
		if (maxl==lt) ans++;
		string tl = "",tr = "";
		for (int j = maxl+2; j <= minr-1; j++) tl+=s[j],tr+=t[j];
		for (int i = maxl+1; i >= 1; i--)
		{
			tl=s[i]+tl,tr=t[i]+tr;
			for (int j = max(maxl,minr); j <= lt+1; j++)
			{
				string ll = tl,rr = tr;
				for (int k = minr; k <= j-1; k++) ll+=s[k],rr+=t[k];
				if (ma[ll]==rr&&ll!="") ans++;
			}
		}
		writech(ans,'\n');
	}
	return 0;
}

