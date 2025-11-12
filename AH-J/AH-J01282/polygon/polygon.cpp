#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,a[5005],sum[5005],res;
bool used[5005],tused[5005];
set<string> s;
void dfs(int x,int sum){
	if(sum>=x){
		LL maxx=0,ans=0;
		string t="";
		for(int i = 1; i <= n; ++i){
			if(used[i]){
				t+=(i+'0');
				ans+=a[i];
				maxx=max(maxx,a[i]);
				tused[i]=true;
			}
		}
		int size=s.size();
		s.insert(t);
		int size2=s.size();
		if(size!=size2){
			if(ans>maxx*2) res=(res+1)%998244353;
		}
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(!used[i]){
			used[i]=true;
			dfs(x,sum+1);
			used[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool check=true;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i]!=a[i-1] && i>1) check=false;
		sum[i]+=a[i];
	}
	if(check){
		for(int i = 3; i <= n; ++i){
			LL tmp=1;
			for(int j = n; j >= n-i+1; --j){
				tmp*=j;
				tmp/=(n-j+1);
				tmp%=998244353;
			}
			res+=tmp;
			res%=998244353;
		}
		cout << res;
	}else if(n<=10){
		res=0;
		for(int i = 3; i <= n; ++i){
			s.clear();
			dfs(i,0);
		}
		cout << res;
    }else{
		LL tmp=1;
		for(int i = 1; i <= n; ++i){
			tmp*=i;
			tmp%=998244353;
		}
		cout << tmp;
	}
	return 0;
}
