#include<bits/stdc++.h>
#define max_n 200005
using namespace std;
int n;
int q;
struct RE
{
	string a;
	string b;
};
RE s[max_n];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	for(int i=1;i<=q;i++)
	{
		string in_one;
		string in_two;
		int ans=0;
		cin>>in_one>>in_two;
		int ttt=in_one.size();
		int rrt=in_two.size();
		if(ttt!=rrt)
		{
			cout<<"0"<<endl;
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			string ft=s[j].a;
			string sd=s[j].b;
			int len=ft.size();
			string re_x=in_one;
			if(in_one==ft&&in_two==sd)
			{
				ans++;
				continue;
			}
			for(int k=0;k<ttt;k++)
			{
				 if(in_one[k]==ft[0])
				 {
				 	int temp=0;
				 	while(in_one[k+temp]==ft[temp])
				 	{
				 		temp++;
					}
					if(temp==len)
					{
						for(int o=k;o<k+temp;o++)
						{
							re_x[o]=sd[o-k];
						}
					}
					if(re_x==in_two)
					{
						ans++;
						re_x=in_one;
						continue;
					}
				 }
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}
