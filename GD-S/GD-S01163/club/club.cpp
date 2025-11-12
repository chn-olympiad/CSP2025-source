#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=3e5+300;
int T;
struct stu
{
	int ind,x,tp;
}s[MAXN];
bool operator<(stu a,stu b)
{
	return a.x>b.x;
}
bool ud[MAXN];
int kk[15];
int n;
int cnt[4];
int ans;

void dfs(int k)
{
	if(k>n)
	{
		int anst=0;
		for(int i=1;i<=n;i++)
			anst+=s[(i-1)*3+kk[i]].x;
		ans=max(ans,anst);
		return;
	}
	if(cnt[1]<n/2)
	{
		kk[k]=1;
		cnt[1]++;
		dfs(k+1);
		cnt[1]--;
	}
	if(cnt[2]<n/2)
	{
		kk[k]=2;
		cnt[2]++;
		dfs(k+1);
		cnt[2]--;
	}
	if(cnt[3]<n/2)
	{
		kk[k]=3;
		cnt[3]++;
		dfs(k+1);
		cnt[3]--;
	}
}
int main()
{
	FILE* fp;
	fp=freopen("club.in","r",stdin);
	fp=freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(int i=1;i<=n*3;i+=3)
			cin>>s[i].x>>s[i+1].x>>s[i+2].x;
		for(int i=1;i<=n*3;i+=3)
		{
			s[i].tp=1;
			s[i+1].tp=2;
			s[i+2].tp=3;
			s[i].ind=s[i+1].ind=s[i+2].ind=(i+2)/3;
		}
		for(int i=1;i<=n;i++)
		{
			ud[i]=false;
		}
		if(n<=10)
		{
			dfs(1);
		}
		else
		{
			sort(s+1,s+3*n+1);
			for(int i=1;i<=n*3;i++)
			{
				if(ud[s[i].ind]||cnt[s[i].tp]>=(n/2)) continue;
				ans+=s[i].x;
				ud[s[i].ind]=true;
				cnt[s[i].tp]++;
			}
		}
		
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}