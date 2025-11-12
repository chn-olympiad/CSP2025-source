#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,c[501],v[501],j;
long long ans;
void dfs(int day,int emp,int r){
	if(day>n) {
		if(emp>=m){
			ans=(ans+1)%998244353;
		}
		return ;
	}
	if(emp>=m){
		long long sum=1;
		for(int i=1;i<=n-day+1;i++)
			sum=(sum*i)%998244353;
		ans=(ans+sum)%998244353;
		return ;
	}
	else{
		for(int i=1;i<=n;i++){
			if(v[i]!=1){
				v[i]=1;
				if(r>=c[i]) {
					r++;
					dfs(day+1,emp,r);
				}
				else
					if(s[day-1]=='0')
						dfs(day+1,emp,r+1);
					else
						dfs(day+1,emp+1,r);
				v[i]=0;
				if(r>=c[i])r--;
			}
		}

	}
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	dfs(1,0,0);
	cout<<ans;
}
