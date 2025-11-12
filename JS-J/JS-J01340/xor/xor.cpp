#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10;

int n,k,last=0,ans=0;
int a[MAXN],r[MAXN],f[1<<21];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        r[i]=r[i-1]^a[i];
        int now=k^r[i];
        if(f[now]>=last&&((last>0)||(f[now]>0)||(now==0))){
            last=i;
            ans++;
        }
        f[r[i]]=i;
    }
    cout<<ans;
    return 0;
}
