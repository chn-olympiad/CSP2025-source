#include<cstdio>
#include<cstring>

#include<algorithm>
#include<queue>
#include<vector>

constexpr int maxs=2.5e6+7;
constexpr int maxn=2e5+9;

int tmp[maxs];

struct AC
{
	int mapping[maxn];
	int len[maxn];
	
	int to[maxs][26];
	int fail[maxs];
	int deg[maxs];
	int id=0;
	
	std::vector<int> hit[maxs];//end of str
	
	int used=1;
	
	void clrans(){
		for(int i=0;i<used;i++)
			hit[i].resize(0);
	}
	
	void insert(char str[])
	{
		int root=0,i=0;
		for(;str[i];i++)
		{
			if(!to[root][str[i]-'a'])
				to[root][str[i]-'a']=used++;
			root=to[root][str[i]-'a'];
		}
		
		len[id]=i;
		mapping[id++]=root;
	}
	
	void build()
	{
		std::queue<int> q;
		
		for(int i=0;i<26;i++)
			if(to[0][i])
				q.push(to[0][i]);
				
		while(q.size())
		{
			int u=q.front();q.pop();
			
			for(int i=0;i<26;i++)
			{
				if(to[u][i])
				{
					fail[to[u][i]]=to[fail[u]][i];
					
					deg[to[fail[u]][i]]++;
					
					q.push(to[u][i]);
				}
				else{
					to[u][i]=to[fail[u]][i];
				}
			}
		}
	}
	
	void match(char str[])
	{
		int root=0;
		for(int i=0;str[i];i++){
			root=to[root][str[i]-'a'];
			hit[root].push_back(i);
		}
		
		std::queue<int> q;
		for(int i=1;i<used;i++)
			if(!(tmp[i]=deg[i]))
				q.push(i);
		
		tmp[0]=maxs;
		
		while(q.size())
		{
			int u=q.front();q.pop();
			
			for(auto p:hit[u])
				hit[fail[u]].push_back(p);
			
			if(!--tmp[fail[u]])
				q.push(fail[u]);
		}
	}
}ACS[2];

char buffer[2][maxs*2];

//30pt

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	int N,Q;scanf("%d%d\n",&N,&Q);
	
	for(int i=0;i<N;i++){
		scanf("%s %s\n",buffer[0],buffer[1]);
		
		ACS[0].insert(buffer[0]);
		ACS[1].insert(buffer[1]);
	}
	
	ACS[0].build();
	ACS[1].build();

	for(int i=0;i<Q;i++)
	{
		scanf("%s %s\n",buffer[0],buffer[1]);
		
		int ldif=-1,rdif,len=0;
		for(;buffer[0][len]&&buffer[1][len];len++){
			if(buffer[0][len]!=buffer[1][len]){
				if(ldif==-1) ldif=len;
				rdif=len;
			}
		}
		
		if(buffer[0][len]||buffer[1][len]){
			puts("0");continue;
		}
		
		ACS[0].clrans();
		ACS[0].match(buffer[0]);
		ACS[1].clrans();
		ACS[1].match(buffer[1]);
		
		int ans=0;
		for(int i=0;i<N;i++)
		{
			if(rdif>=ldif+ACS[0].len[i]) continue;
			
			std::sort(ACS[0].hit[ACS[0].mapping[i]].begin(),
				ACS[0].hit[ACS[0].mapping[i]].end());
			ACS[0].hit[ACS[0].mapping[i]].resize(
				std::unique(ACS[0].hit[ACS[0].mapping[i]].begin(),
				ACS[0].hit[ACS[0].mapping[i]].end())
				-ACS[0].hit[ACS[0].mapping[i]].begin());
			
			std::sort(ACS[1].hit[ACS[1].mapping[i]].begin(),
				ACS[1].hit[ACS[1].mapping[i]].end());
			
			auto cur=std::lower_bound(
				ACS[1].hit[ACS[1].mapping[i]].begin(),
				ACS[1].hit[ACS[1].mapping[i]].end(),rdif);
			
			for(auto it=std::lower_bound(
				ACS[0].hit[ACS[0].mapping[i]].begin(),
				ACS[0].hit[ACS[0].mapping[i]].end(),rdif)
				;it!=ACS[0].hit[ACS[0].mapping[i]].end()
				&&*it<ldif+ACS[0].len[i];
				it++)
			{
				while(cur!=ACS[1].hit[ACS[1].mapping[i]].end()
					&&*cur<*it) cur++;
					
				if(cur==ACS[1].hit[ACS[1].mapping[i]].end())
					break;
					
				if(*cur==*it)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
