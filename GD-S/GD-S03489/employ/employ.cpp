#include<bits/stdc++.h>
using namespace std;
const int maxn=501;
long long int n,m,k,xl[maxn],b[maxn],vis[maxn],ans;
char a[maxn];
void dfs(int x){
	if(x==n+1){
		int cnt=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='0'||b[i]<=cnt)cnt++;
			else cnt2++;
		}
		if(cnt2>=m)ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[x]=xl[i];
			dfs(x+1);
			vis[i]=0;
//			b[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>xl[i];
	}
    int f1=0,f2=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='0'){
			f1=1;f2++;
		}
	}
	if(f1==0){
	//	cout<<1;
		int sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;return 0;
	}
	if(f2==m||(n-f2)<m){
		cout<<0;return 0;
	}
	dfs(1);
	cout<<ans;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
