#include<bits/stdc++.h>
using namespace std;
const int maxn=1048576+5;
int n,k,a[maxn],s[maxn],f[maxn];
int b[maxn];
void Main(){
    cin>>n>>k;
    for(int x=0;x<(1<<20);x++){
        b[x]=-1;
    }
    b[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        f[i]=f[i-1];
        if(b[s[i]^k]!=-1){
            int j=b[s[i]^k];
            f[i]=max(f[i],f[j]+1);
        }
        b[s[i]]=i;
    }
    cout<<f[n]<<'\n';
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    Main();
}