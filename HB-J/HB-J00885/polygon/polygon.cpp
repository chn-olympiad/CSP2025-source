#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5009],cnt=0;
void dfs(string s,int x){
	if(x>n){
		int sumn=0,maxn=-1,flag=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				flag=1;
				sumn+=a[i+1];
				if(a[i+1]>maxn){
					maxn=a[i+1];
				}
			}
		}
		if(sumn<=maxn*2 || flag==0) return ;
		cnt=(cnt+1)%mod;
		return ;
	}
	dfs(s+'0',x+1);
	dfs(s+'1',x+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs("",1);
	cout << cnt;
	return 0;
}
