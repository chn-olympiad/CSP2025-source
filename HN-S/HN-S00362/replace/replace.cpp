#include <bits/stdc++.h>
using namespace std;
const unsigned long long base=131;
const int N=2e5+5;
const int M=5e6+5;
int n,q,tot;
int cnt[N];
string s[5][N],x,y;
struct node
{
	unsigned long long a;
	int id,siz;
};
map<pair<unsigned long long,unsigned long long>,int>mp;
vector<node>v[5][N];
string sub(string a,int l,int r)
{
	string op="";
	for(int i=l;i<=r;i++)op+=a[i];
	return op;
}
unsigned long long hsh(string a)
{
	unsigned long long ans=0;
	for(int i=0;i<(int)a.size();i++)ans=ans*base+a[i];
	return ans;
}
bool cmp(node a,node b){return a.siz<b.siz;}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q; 
	for(int i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
		int l=-1,r=s[1][i].size();
		while(s[1][i][l+1]==s[2][i][l+1])l++;
		while(s[1][i][r-1]==s[2][i][r-1])r--;
		string a=sub(s[1][i],l+1,r-1);
		string b=sub(s[2][i],l+1,r-1);
		unsigned long long opa=hsh(a),opb=hsh(b);
		if(!mp.count(make_pair(opa,opb)))mp[make_pair(opa,opb)]=++tot;
		int id=mp[make_pair(opa,opb)];
		a=sub(s[1][i],0,l);
		reverse(a.begin(),a.end());
		v[1][id].push_back({hsh(a),i,(int)a.size()});
		a=sub(s[1][i],r,s[1][i].size()-1);
		v[2][id].push_back({hsh(a),i,(int)a.size()});
	}
	for(int i=1;i<=tot;i++)sort(v[1][i].begin(),v[1][i].end(),cmp);
	for(int i=1;i<=tot;i++)sort(v[2][i].begin(),v[2][i].end(),cmp);
	while(q--)
	{
		cin>>x>>y;
		if(x.size()!=y.size())cout<<0<<"\n";
		else
		{
			memset(cnt,0,sizeof(cnt));
			int l=-1,r=x.size();
			while(x[l+1]==y[l+1])l++;
			while(x[r-1]==y[r-1])r--;
			int a=hsh(sub(x,l+1,r-1));
			int b=hsh(sub(y,l+1,r-1));
			if(!mp.count(make_pair(a,b)))cout<<"0\n";
			else
			{
				int id=mp[make_pair(a,b)];
				string op=sub(x,0,l);
				reverse(op.begin(),op.end());
				unsigned long long ans=0;
				int point=0;
				while(point<(int)v[1][id].size()&&v[1][id][point].siz==0)
				{
					if(v[1][id][point].a==ans)cnt[v[1][id][point].id]++;
					point++;
				}
				for(int i=0;i<=l;i++)
				{
					ans=ans*base+op[i];
					while(point<(int)v[1][id].size()&&v[1][id][point].siz==i+1)
					{
						if(v[1][id][point].a==ans)cnt[v[1][id][point].id]++;
						point++;
					}
				}
				op=sub(x,r,x.size()-1);
				ans=0;
				int sum=0;
				point=0;
				while(point<(int)v[2][id].size()&&v[2][id][point].siz==0)
				{
					if(v[2][id][point].a==ans)
					{
						cnt[v[2][id][point].id]++;
						if(cnt[v[2][id][point].id]==2)sum++;
					}
					point++;
				}
				for(int i=0;i<(int)op.size();i++)
				{
					ans=ans*base+op[i]; 
					while(point<(int)v[2][id].size()&&v[2][id][point].siz==i+1)
					{
						if(v[2][id][point].a==ans)
						{
							cnt[v[2][id][point].id]++;
							if(cnt[v[2][id][point].id]==2)sum++;
						}
						point++;
					}
				}
				cout<<sum<<"\n";
			}
		} 
	}
	return 0;
}

