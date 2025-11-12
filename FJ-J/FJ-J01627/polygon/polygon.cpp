#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int s[5005];
int ans;
bool b=1;
int answ[203];
void dfs(int i,int sum,int maxx,int cnt){
	if(n==i){
		if(sum>maxx*2 && cnt>=3){
			ans++;
			ans=ans%mod;
//			for(int i=1;i<=cnt;i++){
//				cout<<answ[i]<<" ";
//			}
//			cout<<endl;
		}
		return;
	}
//	answ[cnt+1]=i+1;
	dfs(i+1,sum+a[i+1],a[i+1],cnt+1);
	dfs(i+1,sum,maxx,cnt);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			b=0;
		}
	}
	if(b==1){
		int q=0;
		for(int i=3;i<=n;i++){
			q=(q%mod+q%mod+((i-1)%mod*(i-2)%mod/2)%mod)%mod;
		}
		cout<<q%mod<<endl;
		return 0;
	}
	sort(1+a,1+a+n);
	dfs(0,0,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
//16*4=64   1
