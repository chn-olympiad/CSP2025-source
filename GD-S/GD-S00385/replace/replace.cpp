#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200010;

string a[N],b[N],s,t;
int ans;

bool Solve(string x,string y)
{
	if(s.size() < x.size()) return 0;
//	cout<<x<<' '<<y<<' '<<s.size()<<' '<<x.size()<<endl;
	for(int i = 0;i <= s.size() - x.size();i++)
	{
//		cout<<i<<' '<<s.size() - x.size()<<endl;
		bool flag = 1;
		for(int j = 0;j < x.size();j++)
		{
			if(s[i + j] != x[j])
			{
				flag = 0;
				break;
			}
		}
		if(!flag) continue;
		string ss = s;
		for(int j = 0;j < x.size();j++) ss[i + j] = y[j];
		if(ss == t) return 1;
	}
	return 0;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i;
	cin>>n>>q;
	for(i = 1;i <= n;i++) cin>>a[i]>>b[i];
	while(q--)
	{
		cin>>s>>t;
		ans = 0;
		for(i = 1;i <= n;i++) if(Solve(a[i],b[i])) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
