#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5;
ll a[MAXN];
int n;
int ans;
ll k;
ll sum[MAXN];
map<int ,int>m;
ll read(){
    ll x=0;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar_unlocked();
    }
    return x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read();
    k=read();
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j+i-1<=n;j++){
            while(m.count(j))j=m[j];
            if(j+i-1>n)break;
            if((sum[j+i-1]^sum[j-1])==k){
                m[j]=j+i;
                ans++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
