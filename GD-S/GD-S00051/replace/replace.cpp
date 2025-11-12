#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<chrono>
using namespace std;
using namespace __gnu_pbds;
long long n,q,cnt;
gp_hash_table<string,long long>Hashing;
struct path
{
	string from,to;
}s[200010];
set<long long>graph[400010];
// tree<pair<long long,long long>,null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update>graph[400010];
int main()
{
	double starttime=clock();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i].from>>s[i].to;
		long long from,to;
		if(Hashing.find(s[i].from)==Hashing.end()) Hashing[s[i].from]=cnt+1,from=cnt+1,cnt++;
		else from=Hashing[s[i].from];
		if(Hashing.find(s[i].to)==Hashing.end()) Hashing[s[i].to]=cnt+1,to=cnt+1,cnt++;
		else to=Hashing[s[i].to];
		graph[from].insert(to);
	}
	bool check=0;
	vector<pair<string,string>>queries;
	for(long long tc=1;tc<=q;tc++)
	{
		string from,to;
		cin>>from>>to;
		if(from.size()!=to.size())
		{
			cout<<"0\n";
			continue;
		}
		long long siz=from.size(),l=0,r=siz-1;
		if(!check&&siz<=2000)
		{ 
			while(l<siz&&from[l]==to[l]) l++;
			while(r>=0&&from[r]==to[r]) r--;
			long long ans=0;
			if((clock()-starttime)/CLOCKS_PER_SEC>0.95)
			{
				cout<<"0\n";
				continue;
			}
			for(long long i=0;i<=l;i++)
			{
				long long j=i-1;
				string replacing_from="",replacing_to="";
				while(j<r)
				{
					j++;
					replacing_from+=from[j];
					replacing_to+=to[j];
				}
				while(j<siz)
				{
					if(Hashing.find(replacing_from)==Hashing.end()||Hashing.find(replacing_to)==Hashing.end())
					{
						j++;
						if(j==siz) break;
						replacing_from+=from[j];
						replacing_to+=to[j];
						continue;
					}
					long long id_re_from=Hashing[replacing_from],id_re_to=Hashing[replacing_to];
					if(graph[id_re_from].find(id_re_to)!=graph[id_re_from].end()) ans++;
					j++;
					if(j==siz) break;
					replacing_from+=from[j];
					replacing_to+=to[j];
				}
			}
			cout<<ans<<'\n';
		}
		else
		{
			check=1;
			queries.push_back(make_pair(from,to));
		}
	}
	if(check)
	{
		vector<pair<long long,long long>>graph2[400010];
		gp_hash_table<long long,long long>Hashing2;
		cnt=0;
		for(long long i=1;i<=n;i++)
		{
			long long from1=s[i].from.find('b'),to1=s[i].to.find('b');
			long long val=to1-from1;
			if(Hashing2.find(val)==Hashing2.end()) Hashing2[val]=++cnt;
			graph2[Hashing2[val]].push_back(make_pair(from1,(long long)(s[i].from.size())-from1-1));
		}
		for(long long i=0;i<q;i++)
		{
			long long from1=queries[i].first.find('b'),to1=queries[i].second.find('b');
			long long val=to1-from1;
			if(Hashing2.find(val)==Hashing2.end())
			{
				cout<<"0\n";
				continue;
			}
			long long tmp=Hashing2[val],ans=0;
			auto p=make_pair(from1,(long long)(queries[i].first.size())-from1-1);
			for(auto j:graph2[tmp])
				if(j.first<=p.first&&j.second<=p.second)
					ans++;
			cout<<ans<<'\n';
		}
	}
}
//Why does the bro nearby doing the battle of keyboard-noise with me?I tried so hard,but I couldn't defeat him./oh