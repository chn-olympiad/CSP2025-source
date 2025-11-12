#include<bits/stdc++.h>
using namespace std;
int n,q,n1,len[1005],w1,w2;
string w,s1[1005],s2[1005],t1,t2;
map<string,map<string,int> >v;
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
	}	
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		n1=t1.size();
		t1=' '+t1;
		t2=' '+t2;
		w1=0;
		w2=n1+1;
		for(int j=1;j<=n1;j++)
		{
			if(t1[j]==t2[j])
			{
				w1=j;
			}
			else
			{
				break;
			}
		}
		for(int j=n1;j>=1;j--)
		{
			if(t1[j]==t2[j])
			{
				w2=j;
			}
			else
			{
				break;
			}
		}
//		for(int j=0;j<=w1;j++)
//		{
//			w="";
//			for(int k=max(j+2,w2)-1;k<=n;k++)
//			{
//				w+=
//			}
//		}
	}
}
