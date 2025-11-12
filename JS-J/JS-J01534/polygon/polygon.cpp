#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int MAXN=5010;
const int MOD=998244353;
int n,ans=0,a[MAXN],vh[MAXN];
int vt(int x){
	int js=0,op=x,s[MAXN]={0};
	while(op>0){
		vh[++js]=op%2;
		op/=2;
	}
	//for(int i=1;i<=js;++i)
	//	vh[i]=s[js-i+1];
	//for(int i=1;i<=js;++i)
	//	cout<<vh[i];
	//cout<<endl;
	return js;
}
void dfs(int x){
	int pos=pow(2,x)-1;
	for(int i=1;i<=pos;++i){
		int sum=0,num=0,maxn=-1;
		memset(vh,0,sizeof(vh));
		int len=vt(i);
		for(int j=1;j<=len;++j)
			if(vh[j]==1){
				sum+=a[j],num++;
				maxn=max(maxn,a[j]);
			}
		//cout<<num<<" "<<sum<<" "<<maxn<<endl;
		if(num>=3){
			if(sum>maxn*2) ans++,ans%=MOD;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	dfs(n);
	printf("%d",ans%MOD);
	return 0;
}
