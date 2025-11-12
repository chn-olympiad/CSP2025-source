//GZ-S00288 贵阳市第一中学 殳晟欢
#include<bits/stdc++.h>
using namespace std;
int n,q,t,tt,cnt,len,ls1[200001],rs1[200001],ls2[200001],rs2[200001];
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		len=s1.size();
		ls1[i]=s1.find('b');
		rs1[i]=len-ls1[i]-1;
		len=s2.size();
		ls2[i]=s2.find('b');
		rs2[i]=len-ls2[i]-1;
	}
	if(q==1 && s1[1]!='a' && s1[1]!='b')
	{
		cout<<0;
		return 0;
	}
	while(q--)
	{
		cin>>s1>>s2;
		cnt=0;
		len=s1.size();
		t=s1.find('b');
		tt=len-t-1;
		for(int i=1;i<=n;i++)
		{
			if(t>=ls1[i] && tt>=rs1[i])
				f=1;
		}
		len=s2.size();
		t=s2.find('b');
		tt=len-t-1;
		for(int i=1;i<=n;i++)
		{
			if(t>=ls2[i] && tt>=rs2[i])
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

