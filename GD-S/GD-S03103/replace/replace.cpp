#include <bits/stdc++.h>
using namespace std;
string s1[1005],s2[1005],q1,q2;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for (int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>q1>>q2;
		for (int k=1;k<=n;k++)
		{
			for (int j=0;j<q1.size();j++)
			{
				int flag=0;
				for (int l=j;l<j+s1[k].size();l++)
				{
					if (q1[l]!=s1[k][l-j] || s2[k][l-j]!=q2[l])
					{
						flag=1;
						break;
					}
				}
				for (int l=0;l<j;l++){
					if (q1[l]!=q2[l])
					{
						flag=1;
						break;
					}
				}
				for (int l=j+s1[k].size();l<q1.size();l++){
					if (q1[l]!=q2[l])
					{
						flag=1;
						break;
					}
				}
				if (!flag){
					
					ans++;
				}
			}	
		}
		cout<<ans<<endl;
	}
}
