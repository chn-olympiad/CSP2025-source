#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+5;
const int M=998244353;
int n;
int a[N];
bool bok[N];
long long ans=0;
void dfs(int num,int now,int s,int maxn,int beg){
	if(now==num){
		if(s>2*maxn){
			ans++;
		    ans%=M;
		}
		return;
	}
	for(int i=beg;i<=n;i++){
		if(bok[i]) continue;
		bok[i]=true;
		dfs(num,now+1,s+a[i],a[i],i+1);
		bok[i]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			long long tmp=1;
			for(int j=n;j>n-i;j--){
				tmp*=j;
			}
			for(int j=2;j<=i;j++) tmp/=j;
			ans+=tmp;
			ans%=M;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=5;i++){
		dfs(i,0,0,0,1);
	}
	cout<<ans;
	return 0;
}