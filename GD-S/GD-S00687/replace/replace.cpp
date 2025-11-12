#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q;
struct node
{
	string frm,too;
};
node a[MAXN];
node zhao(string s1,string s2)
{
	int i=0,j=s1.size();
	int fl=0;
	while(i<j&&fl<2)
	{
		if(s1[i]==s2[i]) i++;
		else fl++;
		if(s1[j-1]==s2[j-1]) j--;
		else fl++;
	}
	string stra,strb;
	for(int k=i;k<j;k++)
	{
		stra+=s1[k];
		strb+=s2[k];
	}
	node ans={stra,strb};
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].frm>>a[i].too;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		node tmp=zhao(s1,s2);
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j].frm==tmp.frm&&a[j].too==tmp.too) ans++;
			else if(a[j].frm==s1&&a[j].too==s2) ans++;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
