#include<bits/stdc++.h>
using namespace std;
long long n,q;
struct node{
	string s1,s2;
}a[200005];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	getchar();
	for(int i=1; i<=n; i++)
		cin>>a[i].s1>>a[i].s2;
	for(int k=1; k<=q; k++)
	{
		cin>>s1>>s2;
		int ans=0,t=0,tt=0,ttt=0;
		string ss="",sss="";
			for(int i=0; i<s1.size(); i++)
			{
				if(s1[i]!=s2[i])t=1,ss=ss+s1[i],sss=sss+s2[i];
				if(s1[i]==s2[i]&&t==1)tt=1;
				if(s1[i]!=s2[i]&&tt==1){ttt=1;break;}
			}
			if(ttt==1)cout<<0<<"\n";
			else 
			{
				for(int i=1; i<=n; i++)
					if(s1.find(a[i].s1)==s2.find(a[i].s2)&&a[i].s1.find(ss,0)!=-1&&a[i].s2.find(sss,0)!=-1)ans++;
				cout<<ans<<"\n";
			}
	}
	return 0;
}
