#include<bits/stdc++.h>
using namespace std;
int n,q,te=0,ans;
string s1[200005],s2[200005];
string s3[200005],s4[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if (s1[i]==s2[i]) te++;
	}
	for (int i=1;i<=q;i++)
	{
		cin>>s3[i]>>s4[i];ans=0;
		if (s3[i]==s4[i]) printf("%d\n",te);
		else if (s3[i].size()!=s4[i].size()) printf("0\n");
		else
		{
			for (int j=1;j<=n;j++)
				for (int k=0;k<int(s3[i].size());k++)
					if (int(s3[i].size())-k>=int(s1[j].size()))
						if (s3[i].substr(k,s1[j].size())==s1[j]&&s4[i].substr(k,s2[j].size())==s2[j]&&s3[i].substr(0,k)==s4[i].substr(0,k)
						&&s3[i].substr(k+int(s1[j].size()),int(s3[i].size())-k-int(s1[j].size()))==s4[i].substr(k+int(s1[j].size()),int(s4[i].size())-k-int(s1[j].size()))) ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
