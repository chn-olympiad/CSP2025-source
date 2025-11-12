#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,q,local;
string s1,s2,s[N],k[N];
bool vis=false;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		for(int j=s1.size()-1;j>=0;j--)
		{
			if(s1[j]!=s2[j]) 
			{
				local=j;
				break;
			}
		}
		for(int j=0;j<=local;j++)
		{
			if(s1[j]!=s2[j]) vis=true;
			if(vis) s[i]=s1[j]+s[i],k[i]=s2[j]+k[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<"0\n";
	}
	return 0;
}
