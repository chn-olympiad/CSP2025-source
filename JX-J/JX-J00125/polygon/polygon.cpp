#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5010,mod=998244353;
int n;
int a[N];

ll ans;
void dfs(int x,int sum,int k){

    for(int i=x+1;i<=n;i++){
        dfs(i,sum+a[i],k+1);
    }
    if(k>=2) {
        int l=0,r=n+1,mid;
        while(l+1<r){
            mid=(l+r)/2;
            if(a[mid]<sum){
                l=mid;
            }
            else {
                r=mid;
            }
        }
        if(l>x) {
			ans+=l-x;
			ans%=mod;
			//cout<<sum<<" "<<a[l]<<"\n";
		}


    }
    return;

}
int main(){
    IOS;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(0,0,0);

    /*
    for(int i=1;i<=100;i++){
        if(dp[i]){
            cout<<i<<" "<<dp[i]<<"\n";
        }
    }
*/
    cout<<ans%mod;
    return 0;
}

/*
5
1 2 3 4 5


5
2 2 3 8 10
*/













