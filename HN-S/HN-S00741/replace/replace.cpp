#include<bits/stdc++.h>
using namespace std;
int n,q;
long long ans=0;
string s1[100010],s2[100010];
int cnt[30],id[30][100010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for (int i=1;i<=q;i++)
	{
		for (int j=1;j<=26;j++) cnt[j]=0;
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for (int j=0;j<t1.size();j++) cnt[t1[j]-'a'+1]++,id[t1[j]-'a'+1][cnt[t1[j]-'a'+1]]=j;
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=cnt[s1[j][0]-'a'+1];k++)
			{
				string t=t1;
				bool flag=1;
				for (int pos=0;pos<s1[j].size();pos++)
				{
					if (t[pos+id[s1[j][0]-'a'+1][k]]!=s1[j][pos]){flag=0;break;}
					else t[pos+id[s1[j][0]-'a'+1][k]]=s2[j][pos];
				}
					
				if (flag && t==t2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

