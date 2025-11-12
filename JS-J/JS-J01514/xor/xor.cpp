#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e6+10;
int n,k,a[N],b[N],cnt;
bool check(int x,int t){
    for(int i=x;i<=n;i++){
        t^=a[i];
        if(t==k)return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]^a[i];
        if(b[i]==k){
            cnt++;
            b[i]=0;
            continue;
        }
        if(check(i+1,b[i])) b[i]=0;
    }
    cout<<cnt;
    return 0;
}
