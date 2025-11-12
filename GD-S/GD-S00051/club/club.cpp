#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,cnt[4],students[100010][4],cur[100010];
struct selection
{
	long long val,id1,id2;
};
bool cmp(selection a,selection b)
{
	if(a.val>b.val) return true;
	else if(a.val==b.val&&a.id1<b.id1) return true;
	else return false;
}
struct change
{
	long long id,from,to,n_val;
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<selection>v1;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(long long i=1;i<=n;i++)
		{
			cur[i]=0;
			cin>>students[i][1]>>students[i][2]>>students[i][3];
			v1.push_back(selection{students[i][1],i,1});
			v1.push_back(selection{students[i][2],i,2});
			v1.push_back(selection{students[i][3],i,3});
		}
		sort(v1.begin(),v1.end(),cmp);
		long long ans=0;
		for(auto s:v1)
		{
			auto [val,id1,id2]=s;
			if(!cur[id1])
			{
				cnt[id2]++;
				cur[id1]=id2;
				ans+=val;
			}
		}
		vector<change>v2;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=3;j++)
				for(long long k=1;k<=3;k++)
				{
					if(j==k) continue;
					v2.push_back(change{i,j,k,students[i][k]-students[i][j]});
				}
		}
		sort(v2.begin(),v2.end(),[](change a,change b){return a.n_val>b.n_val;});
		for(auto ch:v2)
		{
			auto [id,from,to,n_val]=ch;
			if(cnt[from]<=n/2||cnt[to]>=n/2||cur[id]!=from) continue;
			cnt[from]--; 
			cnt[to]++;
			cur[id]=to;
			ans+=n_val;
		}
		cout<<ans<<endl;
	}
}
//freopen("Club.in","r",stdout);
//Compared for 5000+ datas