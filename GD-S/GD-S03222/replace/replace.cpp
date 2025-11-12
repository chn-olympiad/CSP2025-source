#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,B=131;
const long long p=1e12+10;
int num=0;
long long s1[N],s2[N];
char c2[N];
long long a,b;
void buha(string s,long long &h)
{
	h=0;
	for(char c:s)
	{
		h=h*B+(c-'a'+1);
		h%=p;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s,t,s3="",t3="";
		cin>>s>>t;
		num++;
		for(int j=s.size()-1;j>=0;j--)
		{
			if(s[j]!=t[j])
			{
				for(int k=0;k<=j;k++)
				{
					s3+=s[k];
					t3+=t[k];
				}
				c2[num]=s[j];
				break;
			}
		}
		buha(s3,s1[num]);
		buha(t3,s2[num]);
		
	}
	for(int i=1;i<=q;i++)
	{
		string q1,q2;
		cin>>q1>>q2;
		if(q1.size()!=q2.size())
		{
			cout<<0<<'\n';
			continue;
		}
		buha(q1,a);
		buha(q2,b);
		int sum=1,ans=0;;
		for(int j=q1.size()-1;j>0;j--)
		{
			if(q1[j]!=q2[j])
			{
				for(int k=1;k<=num;k++)
				{
					if((a%p-sum*(s1[k]-s2[k])%p+p)%p==b%p&&c2[k]==q1[j])
					{
						ans++;
					}
				}
				break;
			}
			sum*=B;
			sum%=p;
		}
		cout<<ans<<'\n';
	}
	return 0;
	
}
