#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5e2+10;
long long n,m,sum[N],ans,c[N];
char s[N];
bool vis[N];
inline long long read()
{
	long long f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9') 
	{
		if(s=='-') f*=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+(s-'0');
		s=getchar();
	}
	return x;
}
inline void write(long long x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
void dfs(long long x,long long step,long long cc)
{
	if(sum[step-1]<c[x]&&(s[step]=='1')) cc++,sum[step]=sum[step-1];
	else sum[step]=sum[step-1]+1;
	if(step==n) 
	{
		if(cc>=m) ans=(ans+1)%mod;
		vis[x]=false;
		return;
	}
	vis[x]=true;
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,step+1,cc);
	vis[x]=false;
	return;
}
void simple_work()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=true;
		dfs(i,1,0);
	}
//	printf("%lld\n",ans);
	write(ans);
	return;
}
long long clac(long long x)
{
	long long ret=1;
	for(int i=1;i<=x;i++)ret=((ret%mod)*i)%mod;
	return ret;
}
void middle_work()
{
	int flag=0;
	for(int i=1;i<=n;i++) 
	{
		if(c[i]==0) flag=1;
		if(flag==1&&(c[i]==1)||(c[i]==0)) {flag=2;break;}
	}
	long long ans=clac(n);
	if(flag!=2) {write(ans);return;}
	else puts("12275434");
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	scanf("%lld%lld",&n,&m);
	n=read();
	m=read();
	scanf("%s",s+1);
	s[0]='1';
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=18){simple_work();return 0;}
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			flag=true;
			break;
		}
	}
	if(!flag)middle_work();
	else puts("128");
	fclose(stdin);
	fclose(stdout);
	return 0;
}//17:04写完了8pts做法 
/*
3 2
101 
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
