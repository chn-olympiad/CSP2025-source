#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+500;
int n,k,m;
int a[MAXN],s[MAXN];
int ans,ans2;
struct A{
    int x,y;
    operator <(const A b){
        if(x==b.x){
            return y<b.y;
        }
        return x<b.x;
    }
}num[10000500];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k>>a[1];
    if(a[1]==1){
        ans2++;
    }
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        if(a[i]==1){
            ans2++;
        }
    }
    if(k==1){
        cout<<ans2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int q=s[i-1]^s[j];
            if(q==k){
                m++;
                num[m].x=i;
                num[m].y=j;
                break;
            }
        }
    }
    sort(num+1,num+1+m);
    int yyy=0;
    for(int i=1;i<=m;i++){
        if(num[i].x>yyy){
            ans++;
            yyy=num[i].y;
        }
    }
    cout<<ans;
    return 0;
}
