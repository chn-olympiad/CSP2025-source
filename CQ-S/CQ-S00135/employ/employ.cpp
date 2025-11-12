#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,c[100010],ans,f1,a[100010],b[100010],use[100010],d[100010],qzh[100010],res;
void dfs(int x){
	if(x==n+1){
		int f=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]<=cnt){
				cnt++;
				continue;
			}
			if(a[i]==1)f++;
			else cnt++;
		}
		if(f>=m)f=1;
		else f=0;
		ans=(ans+f)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(use[i]==0){
			use[i]=1;
			b[x]=c[i];
			dfs(x+1);
			use[i]=0;
		}
	}
}
void dfs2(int x){
	if(x==res+1){
		long long cnt=0,tmp=0,num=1;
		for(int i=1;i<=res;i++)cnt+=c[i];
//		for(int i=1;i<=res;i++)cout<<c[i]<<" ";
//		cout<<"\n";
		if(cnt<m)return;
		cnt=0;
		for(int i=1;i<=res;i++){
			if(c[i]==1){
				cnt++;
				d[i]=b[i]-cnt+1;
			}
			else{
				d[i]=b[i]-cnt-1;
			}
		}
		cnt=0,tmp=0;
//		cout<<"\n---------------------------------------------\n";
//		for(int i=1;i<=res;i++)cout<<c[i]<<" ";
//		cout<<"\n";
//		for(int i=1;i<=res;i++)cout<<d[i]<<" ";
//		cout<<"\n";
		for(int i=res;i>=1;i--){
			if(c[i]==1){
				if(qzh[n]-qzh[d[i]-1]-cnt<=0)return;
//				cout<<qzh[n]-qzh[d[i]-1]-cnt<<" ";
				num=num*(qzh[n]-qzh[d[i]-1]-cnt)%mod;
				cnt++;
			}
			else{
				if(qzh[d[i]]-tmp<=0)return;
//				cout<<qzh[d[i]]-tmp<<" ";
				num=num*(qzh[d[i]]-tmp)%mod;
				tmp++;
			}
		}
//		cout<<"\n";
		for(int i=1;i<=n-res;i++)num=num*i%mod;
//		cout<<num<<"---\n";
		ans=(ans+num)%mod;
		return;
	}
	c[x]=1;
	dfs2(x+1);
	c[x]=0;
	dfs2(x+1);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char opt;
		cin>>opt;
		a[i]=opt-'0';
		if(a[i]==0)f1=1;
		else res++;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else if(f1==0){
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
	}
	else if(m==n){
		cout<<0;
	}
	else if(res<=18){
		res=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)b[++res]=i;
		}
		for(int i=1;i<=n;i++)qzh[c[i]]++;
		for(int i=1;i<=n;i++)qzh[i]+=qzh[i-1];
		dfs2(1);
		cout<<ans;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

10 5
1111111111
6 1 4 2 1 2 5 4 3 3

giao

怎么就快结束了

完了完了我还没来得及写些猎奇的

这还怎么上迷惑行为大赏啊？

不好！

它要破鼎！

助我破鼎

根深蒂固！
*/
