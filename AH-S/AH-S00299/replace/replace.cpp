#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q,i,j;
	string s,qq;
	cin>>n>>q;
	for(int z=1;z<=n;z++)
	{
		cin>>s;
		for(i=0;i<=s.size()-1;i++)
			if(s[i]=='b') break;
		cin>>s;	
		for(j=0;j<=s.size()-1;j++)
			if(s[j]=='b') break;
		a[z]=i-j;
	}
	for(int z=1;z<=q;z++)
	{
		int ans=0;
		cin>>s;
		for(i=0;i<=s.size()-1;i++)
			if(s[i]=='b') break;
		cin>>s;	
		for(j=0;j<=s.size()-1;j++)
			if(s[j]=='b') break;
		for(int x=1;x<=n;x++)
		{
			if(a[x]==i-j) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
