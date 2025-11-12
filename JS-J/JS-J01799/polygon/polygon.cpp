#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=998244353;
int n;
int length[5005];
ll memo[5005];

int qpow(int x){
    if(x==0){
        return 1;
    }
    ll y=2L;
    ll ans=1L;
    while(x!=1){
        if(x%2==1){
            ans=ans*y;
            ans=ans%N;
        }
        x=x/2;
        y=y*y;
        y=y%N;
    }
    ans=(ans*y)%N;
    return ans;
}

int f(int x,int idx,int sum){
    if(sum>length[x]){
        int d=x-idx;
        return qpow(d);
    }
    if(idx==x-1){
        if(sum+length[idx]>length[x]){
            return 1;
        }
        return 0;
    }
    return (f(x,idx+1,sum+length[idx])+f(x,idx+1,sum))%N;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>length[i];
	}
	sort(length+1,length+n+1);
	ll ans=0L;
	for(int i=3;i<=n;i++){
        ans=(ans+f(i,1,0))%N;
	}
	cout<<ans;
    return 0;
}
