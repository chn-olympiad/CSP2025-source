#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,m;
int a[100010];
int f[100010];
string s;
int flag=1;
int num;
int vis[100010];
int ans=0;
void ss(int k,int p)
{
	if(k>n) 
	{
		if(n-p>=m) ans++;
		return ;
	}
    for(int i=1;i<=n;i++)
    {
    	if(!vis[i])
    	{
            vis[i]=1;
            if(a[k]==0) {ss(k+1,p+1);vis[i]=0;continue;}
    		if(p>=f[i]) ss(k+1,p+1);
    		else ss(k+1,p);
    		vis[i]=0;
    	}
    }

}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
    	a[i]=s[i-1]-'0';
    	if(a[i]==0) flag=0;
    }
    for(int i=1;i<=n;i++)
    	scanf("%d",f+i);
    sort(f+1,f+n+1);
    for(int i=1;i<=n;i++)
    {
    	if(f[i]==0) num++;
    }

    if(n-num<m) {cout<<0;return 0;}
    ss(1,0);
    cout<<ans;
	return 0;
}