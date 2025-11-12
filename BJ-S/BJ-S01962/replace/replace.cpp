#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
string t1,t2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			// cout<<i<<"!\n";
			int l=s1[i].size();
			for(int j=0;j+l-1<t1.size();j++)
			{
				// cout<<"!!!\n";
				string c1=t1.substr(0,j);
				string c2=t1.substr(j+l,t1.size()-l+1);
				string c3=c1+s2[i]+c2;
				// cout<<c1<<" "<<c2<<" "<<c3<<"\n";
				if(c3==t2) ans++; 
				// cout<<ans<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}