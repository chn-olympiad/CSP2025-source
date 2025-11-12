#include<iostream>
#include<map>
using namespace std;
int n,q,nxt[10000005],ans;
const long long p=31;
unsigned long long h[3];
string s[200005][3],t[3];
unsigned long long hsh(int x)
{
	unsigned long long sum=0;
	for(char c:t[x])
		sum=sum*p+(c-'a');
	return sum;
}
map<int,bool>mp;
unsigned long long quick_pow(unsigned long long a,int b)
{
	unsigned long long ans=1;
	for(;b;b>>=1)
	{
		if(b&1)
			ans=ans*a;
		a=a*a;
	}
	return ans;
}
bool check(int x,int y)
{
	unsigned long long sum1=0,sum2=0;
	for(int i=y-(int)(s[x][1].size())+1;i<=y;i++)
		sum1=sum1*p+(t[1][i]-'a');
	sum1*=quick_pow(p,(int)(t[1].size())-y-1);
	for(int i=y-(int)(s[x][2].size())+1;i<=y;i++)
		sum2=sum2*p+(t[2][i]-'a');
	sum2*=quick_pow(p,(int)(t[1].size())-y-1);	
	if(h[1]-sum1==h[2]-sum2)
		return true;
	return false;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		ans=0;	
		cin>>t[1]>>t[2];
		h[1]=hsh(1);
		h[2]=hsh(2);			
		for(int i=1;i<=n;i++)
		{
			mp.clear();
			string now=s[i][1]+'?'+t[1];
			for(int j=1;j<(int)(now.size());j++)
			{
				nxt[j]=0;
				int p=nxt[j-1];
				while(p&&now[p]!=now[j])
					p=nxt[p-1];
				if(now[p]==now[j])
					nxt[j]=p+1;
				if(nxt[j]==(int)(s[i][1].size()))
					mp[j]=true;
			}
			now=s[i][2]+'?'+t[2];
			for(int j=1;j<(int)(now.size());j++)
			{
				nxt[j]=0;
				int p=nxt[j-1];
				while(p&&now[p]!=now[j])
					p=nxt[p-1];
				if(now[p]==now[j])
					nxt[j]=p+1;
				if(nxt[j]==(int)(s[i][2].size())&&mp.find(j)!=mp.end()&&check(i,j-s[i][2].size()-1))
					ans++;
			}			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//use cin&&cout
