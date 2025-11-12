#include<bits/stdc++.h>
using namespace std;
const int N=15;
int pl[N];
int n,a[N],r[N],sum[N],q,ans;
string s;
int check(void){
	int cnt=0;
	memset(sum,0,sizeof sum);
	for(int j=0,i=1;j<s.size();i++,j++){
		if(s[j]=='0'){
			sum[i]=sum[i-1]+1;
			continue;
		}
		sum[i]+=sum[i-1];
		if(sum[i]>=r[pl[i]])sum[i]++;
		else cnt++; 
	}
	return cnt;
}
void dfs(int now){
	if(now>n){
		if(check()>=q)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<now;j++){
			if(pl[j]==i){
				flag=0;
				break;
			}
		}
		if(flag){
			pl[now]=i;
			dfs(now+1);
			pl[now]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q>>s;
	for(int i=1;i<=n;i++)cin>>r[i];
	dfs(1);
	cout<<ans;
	return 0;
}
