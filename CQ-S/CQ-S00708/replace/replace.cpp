#include <bits/stdc++.h>
using namespace std;

int n,m;

const int M=2e5+5;
string s1[M],s2[M];
int ll[M],rr[M];
vector<int>kmp[M][5];
int len[M];

void get_kmp(int x, int y, string s)
{
	kmp[x][y].push_back(0);
	kmp[x][y].push_back(0);
	len[x]=s.size();
	s=" "+s;
	int j=0;
	for (int i=2; i<=len[x]; i++)
	{
		while (j and s[j+1]!=s[i]) j=kmp[x][y][j];
		if (s[j+1]==s[i]) j++;
		kmp[x][y].push_back(j);
	}
//	for (int i=1; i<=len[x]; i++)
//	{
//		cout<<kmp[x][y][i]<<" ";
//	}
//	cout<<"\n";
}

int check(int l, int r, string s, int ll, int rr, string t)
{
	if (r-l!=rr-ll) return 1;
	for (int i=1; i<=r-l+1; i++)
	{
		if (s[l+i-1]!=t[ll+i-1]) return 1;
	}
	return 0;
}

int KMP(string t1, string t2, int x)
{
	int t=t1.size();
	t1=" "+t1;
	t2=" "+t2;
	int l=1,r=t;
	while (t1[l]==t2[l]) l++;
	while (t1[r]==t2[r]) r--;
	if (check(l,r,t1,ll[x],rr[x],s1[x])) return 0;
	if (check(l,r,t2,ll[x],rr[x],s2[x])) return 0;
	int jj1=0,jj2=0;
	int ans=0;
	for (int i=1; i<=t; i++)
	{
		while (jj1 and s1[x][jj1+1]!=t1[i]) jj1=kmp[x][1][jj1];
		if (s1[x][jj1+1]==t1[i]) jj1++;
		while (jj2 and s2[x][jj2+1]!=t2[i]) jj2=kmp[x][2][jj2];
		if (s2[x][jj2+1]==t2[i]) jj2++;
		if (jj1==len[x] and jj2==len[x])
		{
			if (i-len[x]+1<=l and i>=r) ans++;
		}
		else if (jj1==len[x]) jj1=kmp[x][1][jj1];
		else if (jj2==len[x]) jj2=kmp[x][2][jj2];
	}
//	cout<<s1[x]<<" "<<s2[x]<<" "<<t1<<" "<<t2<<" "<<l<<" "<<r<<" "<<ans<<"\n";
	return ans;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//cout<<check(2,3," abc",1,2," ab");
	cin>>n>>m;
	for (int i=1; i<=n; i++)
	{
		cin>>s1[i]>>s2[i];
//		cout<<s1[i]<<" "<<s2[i]<<"\n";
		get_kmp(i,1,s1[i]);
		get_kmp(i,2,s2[i]);
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		ll[i]=1,rr[i]=len[i];
		while (s1[i][ll[i]]==s2[i][ll[i]]) ll[i]++;
		while (s1[i][rr[i]]==s2[i][rr[i]]) rr[i]--;
	}
	for (int i=1; i<=m; i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		if (t1.size()!=t2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		int sum=0;
		for (int j=1; j<=n; j++)
		{
			sum+=KMP(t1,t2,j);
		}
		cout<<sum<<"\n";
	}
	return 0;
}

