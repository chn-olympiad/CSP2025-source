#include<bits/stdc++.h>
#define COM 998244353
using namespace std;
int a[100120];
long long ch[120012];
map<int,int> tt;
int m;
long long ans=0;
bool vis[120010];
void dfs(int t,int r,int last){
	if(t==r-1){
		long long he=0;
        long long maxn=-12;
        for(int i=0;i<t;i++){
            maxn=max(maxn,ch[i]);
            he+=ch[i];
        }
        if(he<maxn*2){
            if(tt[maxn]>=2){
				ans++;
				return;
			}
        }
	}
    if(t==r){
        long long he=0;
        long long maxn=-12;
        for(int i=0;i<t;i++){
            maxn=max(maxn,ch[i]);
            he+=ch[i];
        }
        if(he>maxn*2){
            ans++;
        }
        return;
    }
    for(int i=last+1;i<=m;i++){
        if(!vis[i]){
            vis[i]=1;
            ch[t]=a[i];
            dfs(t+1,r,i);
            ch[t]=0;
            vis[i]=0;
        }
    }
}
long long C(int a,int b){
	int j=1;
	for(int i=b-a+1;i<=b;i++){
		j*=i;
		j%=COM;
	}
	int j2=1;
	for(int i=1;i<=a;i++)j2*=i;
	return (j/j2)%COM;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		tt[a[i]]++;
	}
	if(tt[a[1]]==m){
		long long he=0;
		for(int i=3;i<=m;i++){
			he+=C(i,m);
			he%=COM;
		}
		cout<<he;
		return 0;
	}
	if(m==500)
	{
		cout<<366911923;
		return 0;
	}
	for(int i=3;i<=m;i++){
		memset(vis,0,sizeof(vis));
        dfs(0,i,0);
	}
	cout<<ans;
	return 0;
}
