#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200009
#define rep(i,l,r,k) for(int i=l;i<=r;i+=k)
int n,q;
int check_B=1,dis[N];
string a[N],b[N];
map<int,int>fB;
map<string,string>f;
int Check_B(string str)
{
	int len=str.size(),cnta=0,cntb=0,posb;
	for(int i=0;i<len;i++)
	{
		cnta+=(str[i]=='a');
		cntb+=(str[i]=='b');
		if(str[i]=='b') posb=i; 
	}
	return (cnta+cntb==len&&cntb==1 ? posb : -1);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	rep(i,1,n,1) 
	{
		cin>>a[i]>>b[i];
		f[a[i]]=b[i];
		int l_1=Check_B(a[i]),l_2=Check_B(b[i]);
		if(l_1!=-1&&l_2!=-1) fB[l_1-l_2]++;
		else check_B=0;
	}
	if(check_B)
	{
		while(q--)
		{
			string s,ss;
			cin>>s>>ss;
//			cout<<s<<" "<<ss<<endl;
			int l_1=Check_B(s),l_2=Check_B(ss);
			if(l_1!=-1&&l_2!=-1&&s.size()==ss.size())
				cout<<fB[l_1-l_2]<<endl;
		}
	}
	else
	{
		while(q--)
		{
			int ans=0;
			string s,ss;
			cin>>s>>ss;
			int len1=s.size(),len2=ss.size(),l,r;
			if(len1!=len2) 
			{
				cout<<0<<endl; continue;
			}
			rep(i,0,len1-1,1)
				if(s[i]!=ss[i])
				{
					l=i;
					break;
				}
			for(int i=len1-1;i>=0;i--)
				if(s[i]!=ss[i])
				{
					r=i;
					break;
				}
			rep(i,0,l,1)
			{
				string str1="",str2="";
				rep(j,i,r-1,1) str1+=s[j],str2+=ss[j];
				rep(j,r,len1-1,1) 
				{
					str1+=s[j];
					str2+=ss[j];
					ans+=(f[str1]==str2);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

