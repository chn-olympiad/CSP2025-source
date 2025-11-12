#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,k,a[1000010],tmp,fine,sum[5010][5010];
bool xza=1,xzb=1,xzc=1;
ll start(ll x){
    ll ans=0;
    for(int i=x;i<=n;i++){
        tmp^=a[i];
        if(tmp==k) ans++,tmp=0;
    }
    return ans;
}
ll go(ll x){
    if(x>n) return 0;
    for(int j=x;j<=n;j++){//first possible end
        for(int i=x;i<=j;i++){//find the front
            if(sum[i][j]==k) return 1+go(j+1);
        }
    }
    return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) xza=0;
        if(a[i]>1) xzb=0;
        if(a[i]>255) xzc=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ll ans=0;
            for(int k=i;k<=j;k++){
                ans^=a[k];
            }
            sum[i][j]=ans;
        }
    }
    if(xza){
        cout<<n/2;
        return 0;
    }
    if(xzb){
        cout<<start(1);
        return 0;
    }
    cout<<go(1);
	return 0;
}
