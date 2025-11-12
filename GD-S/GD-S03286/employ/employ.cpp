#include<bits/stdc++.h>

using namespace std;

const int N=501,Mod=998244353;
int n,m,ans,len,minn,maxn,c[N],l[N],p[N];
bool vis[N];
string s;

void dfs(int x){
	if(x==n+1){
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]>l[i]+cnt && s[i-1]=='1') sum++;
			else if(c[p[i]]<=l[i]+cnt && s[i-1]=='1') cnt++;
			if(sum>=m){
				ans++,ans%=Mod;
				return;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1,p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		l[i+1]=l[i]+(1^(s[i]-'0'));
		//if(s[i]=='1' && minn=-1) minn=i+1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		//maxn=max(maxn,c[i]);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

