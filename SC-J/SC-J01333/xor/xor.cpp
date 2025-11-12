#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
const int N=5e5+5,M=(1<<20)+5;
int f[N],t[M],n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    int w=0;
    t[0]=1;
    int s=0;
    for(int i=1;i<=n;++i){
        cin>>w,s^=w;
        f[i]=f[i-1];
        // db("%d:%d to %d\n",i,t[s^k],i);
        if(t[s^k]) f[i]=max(f[i],f[t[s^k]-1]+1);
        t[s]=i+1;
    }
    cout<<f[n]<<"\n";
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//8:55
