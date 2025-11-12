#include<bits/stdc++.h>
using namespace std;
int a[5010],sum[5010],n;
long long dfs(int i,int he,int k){
    if(he>k){
        return (long long)pow(2,i)%998244353;
    }
    if(sum[i]+he<=k){
        return 0;
    }
    return dfs(i-1,he,k)+dfs(i-1,he+a[i],k)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	long long cnt=0;
	for(int i=3;i<=n;i++){
        cnt+=dfs(i-1,0,a[i]);
        cnt%=998244353;
	}
	cout<<cnt;
	return 0;
}
