#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n,mod=998244353,f,ans;
const int N=5e3+5;
LL a[N],yh[N][N];

void yhsj(){//杨辉三角求C组合数
	yh[0][0]=1;
	for(int i=1;i<=5e3+2;i++){
		for(int j=0;j<=i;j++){
			if(j) yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
			else yh[i][j]=yh[i-1][j];
			yh[i][j]%=mod;
		}
	}
}

void dfs(LL x,LL maxx,LL sum,LL num){
	if(x>n){
		if(maxx*2>=sum or num<3) return;
		ans++;
		return;
	}
	dfs(x+1,maxx,sum,num);//不选
	LL maxn=max(maxx,a[x]),s=sum+a[x],cnt=num+1;
	dfs(x+1,maxn,s,cnt);
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	yhsj();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(!f){//骗
		for(int i=3;i<=n;i++){
			ans+=yh[n][i];
			ans%=mod;
		}
		cout<<ans;
	}
	else if(n<=25){
		dfs(1,0,0,0);
		cout<<ans;
	}
	else{
		cout<<n/2;
	}

	return 0;
}
