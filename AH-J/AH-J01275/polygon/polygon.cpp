#include<bits/stdc++.h>
using namespace std;
int a[6000];
int n;
long long cnt=0;
int mod=998244353;
void dfs(int i,int k,int sum,int l){
    if(i==n){
		if(k>=3&&sum>2*l){
            cnt++;
            cnt=cnt%mod;
         }
		return;
	}
    dfs(i+1,k+1,sum+a[i],a[i]);
    dfs(i+1,k,sum,l);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    dfs(0,0,0,0);
    cout<<cnt%mod;
    return 0;
}
