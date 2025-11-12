//GZ-S00370 遵义第四初级中学 罗若渊  
#include<bits/stdc++.h>
using namespace std;
int n,q;
struct qq
{
	string a,b;
}s[100000];


int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	for(int i=0;i<q;i++)
	{
		int ans=0;
		string x,y;
		cin>>x>>y;
		for(int j=0;j<n;j++)
		{
			
			for(int k=0;k<=x.size()-s[j].a.size();k++)
			{
				bool p=1;
				for(int l=k;l<=l+s[j].a.size();l++)
				{
					if(x[l]!=s[j].a[l-k])p=0;
				}
				if(p)
				{
					string o;
					for(int l=0;l<k;l++)
					{
						o+=x[l];
					}
					for(int l=k;l<=l+s[j].a.size();l++)
					{
						o+=s[j].a[l-k];
					}
					for(int l=l+s[j].a.size()+1;l<x.size();l++)
					{
						o+=x[l];
					}
					if(o==y)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	
 	return 0;	
} 
/*
Ren5Jie4Di4Ling5%


3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0





*/
