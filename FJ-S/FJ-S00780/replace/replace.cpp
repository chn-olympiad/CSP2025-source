#include<bits/stdc++.h>
using namespace std;
struct char1
{
	string a;
	string b;
};
char1 a[1000000];
char1 s;
int m;
int ans=0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	for(int j=1;j<=q;j++)
	{
		cin>>s.a>>s.b;
		for(int i=0;i<n;i++)
		{
			if(s.a==a[i].a&&s.b==a[i].b)
			{
				ans++;
			}
			string s7=s.a;
			string s8=s.b;
			long long s5=s.a.find(a[i].a);
			long long s6=s.b.find(a[i].b);
			if(s5==s6)
			{
			long long s1=a[i].a.size();
			long long s2=a[i].b.size();
			for(int k=0;k<s5;k++)
			{
				if(s.a[k]==s.b[k])
				{
				//	cout<<s.a[k]<<" "<<s.b[k]<<endl;
					m++;
				}
				
			}
		//	cout<<s5<<endl;
			if(m==s5)
			{
				m=0;
				for(int k=s5+s1;k<s.a.size();k++)
				{
					if(s.a[k]==s.b[k])
					{
					//	cout<<s.a[k]<<" "<<s.b[k]<<endl;
						m++;
					}
				
				}
				
			}if(m==s5&&m!=0)
				{
					ans++;
				}	
			
		}m=0;
	}
		cout<<ans<<endl;
		ans=0;
	}
}
