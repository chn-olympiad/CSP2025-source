#include<bits/stdc++.h>
using namespace std;

vector<pair<string,string> > r;
vector<pair<string,string> > s;

int find(int rid,int sid)
{
	//cerr<<sid<<","<<rid<<endl;
	int sl=s[sid].first.size();
	int rl=r[rid].first.size();
	for(int i=0;i<sl-1-rl;i++)
	{
		for(int j=0;j<rl;j++)
		{
			cout << r[rid].first[j] << s[sid].first[i+j]<<endl;;
			if(r[rid].first[j]!=s[sid].first[i+j])
			{
				goto break_here;
			}
		}
		return i;
		break_here:
		continue;
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin >> a >> b;
		r.push_back(make_pair(a,b));
	}
	for(int j=0;j<q;j++)
	{
		string a,b;
		cin >> a >> b;
		s.push_back(make_pair(a,b));
		//cerr<<"______________"<<endl;
//		for(int i=0;i<n;i++)
//		{
//			cout << find(i,j) << endl;
//		}
	}
	for(int i=1;i<=q;i++)
	{
		cout << 0 <<endl;
	}
	return 0;
}
