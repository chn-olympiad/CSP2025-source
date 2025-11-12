#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,V=1<<20|5;
int n,k,a[N],buc[V];
void Work(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    int ans=0;
    ++buc[0];
    for(int i=1,j=0;i<=n;++i){
        if(buc[a[i]^k]){
            ++ans;
            while(j<i) --buc[a[j++]];
        }
        ++buc[a[i]];
    }
    printf("%d\n",ans);
}
int main(){
    freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    Work();
    fclose(stdin),fclose(stdout);
    return 0;
}