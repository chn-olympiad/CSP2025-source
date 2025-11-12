#include<bits/stdc++.h>
using namespace std;
struct z{
    int l,r;
}s[100005];
long long n,k,a[500005],b[100005],m,d,cnt;
bool cmp(z a,z b){
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
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if((b[i]^b[j-1])==k){
                m++;
                s[m].l=j;
                s[m].r=i;
            }
        }
    }
    sort(s+1,s+1+m,cmp);
    cnt=1;
    d=s[1].r;
    for(int i=2;i<=m;i++){
        if(s[i].l>d){
            cnt++;
            d=s[i].r;
        }
    }
    cout<<cnt;
    return 0;
}
