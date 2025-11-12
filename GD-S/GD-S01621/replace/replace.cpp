#include<iostream>
#include<string>
using namespace std;
int n,m;
const int N=2e5+10;
struct node{
	string s;
}ss[N][3],tt[N][3];
bool check(int now,string f)
{
	if(f==ss[now][2].s) return true;
	if(f.size()>ss[now][2].s.size()) return false;
	int l;
	for(int i=0;i<ss[now][2].s.size();i++)
	{
		string ff;
		int kk=1;
		for(int j=i;j<f.size();j++)
		{
			if(ff[j-i]!=ss[now][2].s[j]) 
			{
				kk=0;
				break;
			}
		}
		if(kk)
		{
			return true;
		}
	}
	return false;
	return true;
} 
int main() 
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	string k;
	getline(cin,k);
	for(int i=1;i<=n;i++)
	{
		getline(cin,ss[i][1].s);
		getline(cin,ss[i][2].s);
	} 
	for(int i=1;i<=m;i++)
	{
		getline(cin,tt[i][1].s);
		getline(cin,tt[i][2].s);
		int l=-1,r=-1;
		int ans=0;
		for(int j=0;j<tt[i][1].s.size();j++)
		{
			if(tt[i][1].s[j]!=tt[i][2].s[j])
			{
				if(l==-1) l=j;
				r=j;
			}
			string f,ff;
			for(int j=l;j<r;j++)
			{
				ff+=tt[i][2].s[j];
				f+=tt[i][1].s[j];
			} 
			for(int e=1;e<=n;e++)
			{
				if(ss[e][1].s.size()<f.size()) continue;
				if(ss[e][1].s==f)
					if(check(e,ff)) ans++;
				else
				{
					for(int ii=0;ii<ss[e][2].s.size();ii++)
					{
						string fff;
						int kk=1;
						for(int jj=i;jj<ff.size();jj++)
						{
							if(fff[jj-i]!=ss[e][2].s[jj]) 
								{
									kk=0;
									break;
								}
						}
						if(kk)
						{
							if(check(e,ff)) ans++;;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
