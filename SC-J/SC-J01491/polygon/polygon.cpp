#include<bits/stdc++.h>
using namespace std;
namespace solve{
	inline int read(){
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
		return x*f;
	}
	int n,a[5005],rlt=0;
	void dfs(int now,int max,int sum,int m){
		if(now>n){
			if(m>=3&&sum>max*2)
				rlt++;
			return void();
		}
		dfs(now+1,max,sum,m);
		dfs(now+1,std::max(max,a[now]),sum+a[now],m+1);
		return void();
	}
	int solve(){
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		dfs(1,0,0,0);
		cout<<rlt;
		return 0;
	}
}
int main(){return solve::solve();}