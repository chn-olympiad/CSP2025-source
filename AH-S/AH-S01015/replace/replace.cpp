
#include<bits/stdc++.h>
using namespace std;

int n,q;
string s1,s2;
int a1,a2,ans;
unordered_map<int,int> t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1,j=0;i<=n;i++)
	{
		cin>>s1>>s2;
		while(s1[j]!='b')
			j++;
		a1=j;
		j=0;
		while(s2[j]!='b')
			j++;
		a2=j;
		t[a1-a2]++;
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		a1=a2=0;
		while(s1[a1]!='b')
			a1++;
		while(s2[a2]!='a')
			a2++;
		cout<<t[a1-a2]<<'\n';
	}
	
	return 0;
}
