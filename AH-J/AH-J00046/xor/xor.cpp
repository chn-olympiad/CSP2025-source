#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],t[10005][10005],c,cc=1;
struct aa{
    int l,r;
}b[100000005];
bool cmp(aa a,aa b){
    return a.r<b.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(j==i){
                t[i][j]=a[i];
            }else{
                t[i][j]=t[i][j-1]^a[j];
            }
            if(t[i][j]==k){
                b[++c].l=i;
                b[c].r=j;
            }
        }
    }
    if(c==0){
        cout<<0;
        return 0;
    }
    sort(b+1,b+1+c,cmp);
    long long p=b[1].r;
    for(int i=2;i<=c;i++){
        if(b[i].l>p){
            p=b[i].r;
            cc++;
        }
    }
    cout<<cc;
    return 0;
}
