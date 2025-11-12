#include<bits/stdc++.h> 
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N],ans;

void dfs(int x,int maxn,int sum,int cnt,int op){
	if(sum>maxn*2&&cnt>2&&op==1)	ans++,ans%=mod;
	if(x>n)	return;
	dfs(x+1,maxn,sum,cnt,0);
	dfs(x+1,max(maxn,a[x]),sum+a[x],cnt+1,1);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=20)dfs(1,0,0,0,0);
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]>1)	cnt++;
		}
		if(cnt>=3){ 
			for(int t=3;t<=cnt;t++){
				int num=0;
				long long a=1,b=1;
				while(num<cnt){
					a*=(n-num);
					b*=(cnt-num);
					if(num%3==0){
						a/=b;b=1;
					}
					num++;
				}
				ans+=(a/b);ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}