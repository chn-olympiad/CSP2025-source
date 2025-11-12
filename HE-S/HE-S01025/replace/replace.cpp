#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,int> m;
int n,q;
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		m[make_pair(s1,s2)]++;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			printf("0\n");
			continue;
		}
		for(int l=1;l<=s1.length();l++)
		{
			for(int j=0;j+l<=s1.length();j++)
			{
				string ss1=s1.substr(j,l),ss2=s2.substr(j,l);
				if(m[make_pair(ss1,ss2)]==0)continue;
				string s=s1.substr(0,j)+ss2+s1.substr(j+l,s1.length()-l-j);
				if(s==s2)ans+=m[make_pair(ss1,ss2)];
			}
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
