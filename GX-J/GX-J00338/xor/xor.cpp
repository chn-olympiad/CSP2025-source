#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define c(x) cout<<x<<"<"<<endl
using namespace std;
const int fet=5e5+10;
int n,k,s;
int a[fet];
int t_;
int lost[fet];

void add(int x){
    lost[++t_]=s; s^=a[x];
}
void del(int x){
    s=lost[t_--];
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
        int ans1=0;
        for(int i=1;i<=n;i++){
            s^=a[i];
            if(s==k) ans1++;
        }
    int L=0,R=0;
    int ans=0; s=0;
    while(L<=n&&k!=0){
        while(s<k) add(++L);
        while(s>k) del(++R);
        if(s==k){
            ans++;
            while(R<L) del(++R);
        }
    }
    cout<<max(ans1,ans);
    return 0;
}
