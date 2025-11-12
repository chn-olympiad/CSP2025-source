#include<bits/stdc++.h>
using namespace std;
pair<string,string> a[200005];
pair<string,string> zhui[200005];
int len[200005];
string s1, s2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
		cin >> a[i].first >> a[i].second;
		zhui[i]={"",""};
		for(int j=0;j<(int)a[i].first.size();j++)
		{
			if(a[i].first[j]!=a[i].second[j])
			{
				break;
			}
			zhui[i].first=zhui[i].first+a[i].first[j];
		}
		for(int j=((int)a[i].first.size())-1;j>=0;j--)
		{
			if(a[i].first[j]!=a[i].second[j])
			{
				break;
			}
			zhui[i].second=a[i].first[j]+zhui[i].second;
		}
		len[i]=(int)(a[i].first.size())-(int)(zhui[i].first.size())-(int)(zhui[i].second.size());
	}
	while(q--)
	{
		cin >> s1 >> s2;
		if((int)s1.size()!=(int)s2.size())
		{
			cout << "0\n";
			continue;
		}
		if(s1==s2)
		{
			cout << "1\n";
			continue;
		}
		int l=0, r=0;
		for(int i=0;i<(int)s1.size();i++)
		{
			if(s1[i]!=s2[i])
			{
				l=i;
				break;
			}
		}
		for(int i=(int)(s1.size())-1;i>=0;i--)
		{
			if(s1[i]!=s2[i])
			{
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(len[i]!=r-l+1)
			{
				continue;
			}
			int nl=l-(int)zhui[i].first.size();
			int nr=r+(int)zhui[i].second.size();
			if(s1.substr(nl,nr-nl+1)==a[i].first && s2.substr(nl,nr-nl+1)==a[i].second)
			{
				ans++;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
/*
1
4
1 0 0
1 0 0
2 0 0
2 0 0
*/
