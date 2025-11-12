#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+100;
int n,q;
pair<string,string>a[N];
string s1,s2; int sz,ans=0;
int ff[N];
void dfs(int x)
{
//	cout<<x<<' '<<s1[x]<<s2[x]<<endl;system("pause");
	if(x>=sz) 
	{
		ans++;
	//	cout<<"ans: "<<ans<<endl;
		return ;
	}
	if(s1[x]==s2[x])
	{
//		cout<<"fuck!";
//		system("pause");
		dfs(x+1);
	}
	for(int i=1;i<=n;i++)
	{
		if(ff[i]) continue;
		if(x+a[i].first.size()>sz) continue;
	//	cout<<x<<' '<<i<<endl;
		bool f=1;
		for(int j=x;j<x+a[i].first.size();j++)
		{
		//	if(x==2 and i==3) cout<<j<<' '<<s1[j]<<' '<<a[i].first[j-x]<<' '<<s2[j]<<' '<<a[i].second[j-x]<<endl; 
			if(s1[j]!=a[i].first[j-x] or s2[j]!=a[i].second[j-x])
			{
				f=0;
				break;
			}
		}
	//	if(x==0 and i==1) cout<<"fuck! "<<f<<endl;
		if(f)
		{
			ff[i]=1;
			dfs(x+a[i].first.size());
			ff[i]=0;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	
	
	while(q--)
	{
		cin>>s1>>s2;
		sz=s1.size();
		ans=0;
		dfs(0);
		cout<<ans<<"\n";
	}
		
	return 0;
}
