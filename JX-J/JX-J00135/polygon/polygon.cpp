#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5000+5;
int a[N];
ll s[N],cnt;
int n;
bool check(int l,int r){
    int maxn=0;
    for(int i=l;i<=r;i++){
        maxn=max(maxn,a[i]);
    }
    return s[r]-s[l-1]>2*maxn;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n-1);
    for(int i=1;i<=n;i++){
        s[i]=(ll)(s[i-1]+a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=3;j<=n;j++){
            if(check(i,j)){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
