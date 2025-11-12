#include<bits/stdc++.h>
using namespace std;
string a,b[200005][4],c;
bool cp(int l,string A)
{
	for(int i=l;i<l+A.length();i++)
	{
		//cout<<A[i-l]<<" "<<a[i]<<endl;
		if(l>=a.length()||A[i-l]!=a[i])
		{
			return 0;
		}
	}
	//cout<<"------\n";
	return 1;
}
int main()
{
	freopen("replace.in","r", stdin);
	freopen("replace.out","w", stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i][1]>>b[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>c;
		string aa;
		int ans=0;
		for(int j=0;j<a.length();j++)
		{
			for(int k=1;k<=n;k++)
			{
				//cout<<"----------------------------1-----------------------------";
				aa=a;
				if(!cp(j,b[k][1]))
				{
					continue;
				}
				int q=b[k][1].length();
				if(j+q-1<a.length())
				{
					//cout<<"----------------------------2------------------------------";
					string e=b[k][2];
					if(j+q<a.length())
					{
						e=e+a[j+q];
					}
					//cout<<e<<" ";
					aa.replace(j,j+q,e);
				}
				//cout<<aa<<" "<<c<<endl;
				if(aa==c)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
