#include<bits/stdc++.h>
using namespace std;
int n,q;
string st1[210000],st2[210000],st3,st4;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>st1[i]>>st2[i];
	while(q--)
	{
		cin>>st3>>st4;
		int len1=st3.size();
		int len2=st4.size();
		if(len1!=len2)
		{
			printf("0\n");
			continue;
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			int len=st1[i].size();
			for(int j=0;j+len-1<len1;j++)
			{
				string st5=st3.substr(j,len);
				if(st5!=st1[i])continue;
				string st6=st3.substr(0,j)+st2[i]+st3.substr(j+len,len1-(j+len));
				if(st6==st4)s++;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
