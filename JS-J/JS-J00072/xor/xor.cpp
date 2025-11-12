#include <bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
}qu[500005];
int n,k,a[500005],s[500005],cnt=0,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int he=s[j]^s[i-1];
            if(he==k){
                qu[++cnt]={i,j};
            }
        }
    }
    int num=cnt;
    for(int i=1;i<num;i++){
        if(qu[i].r>=qu[i+1].l){
            cnt--;
            qu[i+1].l=qu[i].l;qu[i+1].r=qu[i].r;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
