#include<bits/stdc++.h>
using  namespace std;
int n,q;
char a[1005][3][2005];
string s1,s2;
vector<int>w[30];
int f(int i)
{
	int ans=0;
	for(int o=0;o<w[a[i][1][0]-97].size();o++)
	{
		int pd=1;
	//	cout<<w[a[i][1][0]-97][o]<<a[i][1][0]<<endl;
		for(int j=0;j<w[a[i][1][0]-97][o]&&pd;j++)
		{
			if(s1[j]!=s2[j]) pd=0;
		}
	//	cout<<pd<<"q";
		int j=w[a[i][1][0]-97][o],k=w[a[i][1][0]-97][o];
		for(;j-w[a[i][1][0]-97][o]<strlen(a[i][1])&&pd;j++)
		{
			if(s1[j]!=a[i][1][j-w[a[i][1][0]-97][o]])pd=0;
		}
	//	cout<<pd<<"q";
		for(;k-w[a[i][1][0]-97][o]<strlen(a[i][2])&&pd;k++)
		{
			if(s2[k]!=a[i][2][k-w[a[i][1][0]-97][o]]) pd=0;
		}
		if(s1.size()-j!=s2.size()-k) pd=0;
		for(;k<s2.size()&&pd;)
		{
			if(s1[j]!=s2[k]) pd=0;
			j++;
			k++;
		}
	//	cout<<pd<<"q"<<endl;
		ans+=pd;
	//	cout<<ans<<endl;
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		int ans=0;
		for(int o=0;o<s1.size();o++)
		{
			w[s1[o]-'a'].push_back(o);
		}
		for(int o=1;o<=n;o++)
		{
			ans+=f(o);
		}
		cout<<ans<<endl;
	}
	return 0;
}
