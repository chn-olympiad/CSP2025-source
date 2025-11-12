//GZ-S00358 遵义航天高级中学 罗上
#include<fstream>
#include<set>
#include<map>
#include<string>
#include<algorithm>
int MOD=998244353;
int peo[500];
int ac[500];
int jie[501],k=1;
int ans;
bool huan[500];
std::string str;
int n,m;
int x=1;
void check(int x,int y,int count)
{
	std::swap(peo[x],peo[y]);
	huan[x]=huan[y]=1;
	if(ac[x]>peo[y]&&ac[y]<peo[y])
	{
		count--;
	}
	else if(ac[x]<peo[y]&&ac[y]>peo[y])
	{
		count++;
	}
	if(ac[y]>peo[x]&&ac[x]<peo[x])
	{
		count--;
	}
	else if(ac[y]<peo[x]&&ac[x]>peo[x])
	{
		count++;
	}
	if(count>=m)
	{
		ans+=x;
		ans%=MOD;
	}
	for(int i=x+1;i<n;i++)
	{
		for(int j=x+1;j<n;j++)
		{
			if(!huan[i]&&!huan[j]&&peo[i]!=peo[j])
			{
				check(i,j,count);
			}
		}
	}
	std::swap(peo[x],peo[y]);
	huan[x]=huan[y]=0;
}
int main()
{
	jie[1]=1;
	std::ifstream cin("employ.in",std::ios::in);
	std::ofstream cout("employ.out",std::ios::out);
	cin>>n>>m>>str;
	ac[0]=(str[0]=='0')?1:0;
	for(int i=1;i<n;i++)
	{
		ac[i]=ac[i-1]+((str[0]=='0')?1:0);
	}
	std::set<int> SET;
	std::map<int,int> MAP;
	for(int i=0;i<n;i++)
	{
		cin>>peo[i];
		SET.insert(peo[i]);
		MAP[peo[i]]++;
	}
	for(std::set<int>::iterator it=SET.begin();it!=SET.end();it++)
	{
		if(MAP[*it]<k)
		{
			x*=jie[MAP[*it]];
			x%MOD;
		}
		else
		{
			for(;k<=MAP[*it];k++)
			{
				jie[k]=jie[k-1]*k;
				jie[k]%=MOD;
			}
		}
	}
	std::sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(!huan[i]&&!huan[j]&&peo[i]!=peo[j])
			{
				ckeck(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}
