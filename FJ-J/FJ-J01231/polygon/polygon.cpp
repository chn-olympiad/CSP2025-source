#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7,mod=998244353;
//T4 :60+pts
//注意 freopen用了吗 ll要开吗 N大小够吗 
int a[N],chose[N],n,ans,lastpos;bool st[N];
void dfs(int ch,int maxch){
	if(ch==maxch){
		int sum=0,maxn=-177777777;
		for(int i=0;i<maxch;i++){
			sum+=chose[i];
			//cout<<chose[i]<<" ";
			maxn=max(maxn,chose[i]);
		}
		if(sum>2*maxn){
			ans++;
			ans%=mod;
			//cout<<"-------------";
		}
		//puts("");
		return ;
	}
	for(int i=lastpos+1;i<=n;i++){
		if(!st[i]){
			st[i]=1;
			chose[ch]=a[i];
			lastpos=i;
			dfs(ch+1,maxch);
			st[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=20){
		long long sum=0;
		for(int i=3;i<=n;i++){
			long long ans=1;
			for(int j=n,f=1;j>=n-i+1;j--,f++){
				ans*=j;
				ans/=f;
				ans%=mod;
			}
			sum+=ans;
			sum%=mod;
		}
		cout<<sum;
		return 0;
	}
	
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		memset(st,0,sizeof st);
		memset(chose,0,sizeof chose);
		lastpos=0;
		dfs(0,i);
	}
	cout<<ans;
	return 0;
}

/*  p_q  */
