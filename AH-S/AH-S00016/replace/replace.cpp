#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int main()
{
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		int sum=0;
		string sa,sb;
		cin>>sa>>sb;
		int l1;
		l1=sa.length()-1;
		int p,t;
		int qian1,qian2,hou1;
		for(int j=0;j<=l1;j++)
		{
			if(sa[j]=='b')
			{
				p=j;
				break;
			}
			if(sb[j]=='b')
			{
				t=j;
				break;
			}
			qian1=p;
			hou1=l1-1-qian1;
			qian2=t;
		}
		for(int j=1;i<=n;j++)
		{
			int qian3,qian4,hou3;
			int l3=s1[j].length()-1;
			for(int g=0;g<=l3;g++)
			{
				if(s1[j][g]=='b')
			    {
			    	qian3=g;
			    	break;
		    	}
		    	if(s2[j][g]=='b')
			    {
		    		qian4=g;
		    		break;
		    	}
		    	hou3=l3-1-qian3;
			}
			if(qian3<=qian1&&hou3<=hou1)
			{
				if(qian1-qian3==qian2-qian4)
				    sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
