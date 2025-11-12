#include<bits/stdc++.h>
using namespace std;
int l[200010],he,we;
string s1,s2,c1,c2,t1,t2;
bool pd(int i,int j)
{
	for(int k=l[i];k<l[i+1];k++)
		if(he+k-j<0||s1[k]!=t1[he+k-j]||s2[k]!=t2[he+k-j])
			return 0;
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,t;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>c1>>c2;
		s1+=c1;s2+=c2;
		l[i+1]=l[i]+c1.size();
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		he=0;we=t1.size();t=0;
		while(t1[he]==t2[he])
			he++;
		while(t1[we]==t2[we])
			we--;
		for(int i=1;i<=n;i++)
		{
			int len=we-he+1;
			for(int j=l[i];j<l[i+1];j++)
				if(s1[j]==t1[he]&&s2[j]==t2[he]&&l[i+1]-j>=len)
					if(pd(i,j))
						t++;
		}
		printf("%d",t);
	}
	return 0;
}