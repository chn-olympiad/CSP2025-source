#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,cnt;
string s1,s2,t1,t2,tq,th,s;
map<string,string> mp;
map<string,bool> m2;
signed main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		mp[s1]=s2;
		m2[s1]=1;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		cnt=0;
		for(int j=0;j<t1.size();j++)
		{
			s="";
			for(int k=j;k<t1.size();k++)
			{
				s+=s[k];
				tq=t1.substr(0,j)+mp[s]+t1.substr(k+1,t1.size()-j-s.size());
				cout<<tq<<endl;
				if(tq==t2)  cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
