#include<bits/stdc++.h>
    using namespace std;
    long long a[5010],cnt=0,k[5010];
    void dfs(int pre,int sum,int geshu,int ko){
    if(geshu>=2&&sum>a[ko+1]){
    cnt++;
    cnt%=998244353;
    }
    for(int i=pre+1;i<=ko;i++){
    dfs(i,sum+a[i],geshu+1,ko);
    }
    }
    int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[n]==1){
		k[0]=1;
		for(int i=1;i<=n/2;i++){
			k[i]=k[i-1]*(n-i+1)/i;
		}
		for(long long i=n;i>=3;i--){
			long long p=min(i,n-i);
			s+=k[p];
			s%=998244353;
		}
		cout<<s;
		return 0;
	}
    for(int i=3;i<=n;i++){
    cnt=0;
    dfs(0,0,0,i-1);
    cnt%=998244353;
    s+=cnt;
    s%=998244353;
    }
    cout<<s;
    return 0;
    }
