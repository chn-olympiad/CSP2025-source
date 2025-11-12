#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,n,m,a[501],pat[501],ocp[501],r,j,k,ans,pass[501],multi[501];
string s;
const ll q=998244353;
ll mul(ll x){
	if(multi[x])return multi[x];
	ll i=1;
	for(ll j=1;j<=x;j++)i=i*j%q;
	return i;
}
ll dfs(ll d,ll num){
	ll ans=0;
	if(num==m)
		return mul(n-pass[d-1]);
	if(d>n||(pass[n]-pass[d-1]+num<m))return 0;
	if(a[d]==0)return dfs(d+1,num);
	for(ll i=1;i<=n;i++){
		if(ocp[i]==0){
			ocp[i]=1;
			if(pat[i]>d-1-num)ans+=dfs(d+1,num+1);
			else ans+=dfs(d+1,num);
			ocp[i]=0;
		}
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(i=1;i<=n;i++){
		cin>>pat[i];
		pass[i]=pass[i-1];
		if(s[i]=='1'){
			a[i]=1;
			pass[i]++;
		}
	}
	if(pass[n]<m){
		cout<<0;
		return 0;
	}
	if(m==1&&pass[n]==n){
		ll al=mul(n);
		sort(pat+1,pat+1+n);
		ll plan=1;
		for(i=1;i<=n;i++){
			ll sum=0;
			for(ll j=1;j<=n;j++){
				if(pat[j]<i)sum++;
				else break;
			}
			if(sum<i){
				plan=0;
				break;
			}
			plan=plan*(sum-i+1);
		}
		cout<<(al+q-plan)%q;
		return 0;
	}
	cout<<dfs(1,0)%q;
}
