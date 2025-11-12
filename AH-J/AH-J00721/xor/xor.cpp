#include<bits/stdc++.h>
using namespace std;

int n,k,a[1300000],ans;

struct qu_jian {
    int l;
    int r;
}b[10000];

bool is_(int l,int r) {
    int sum=a[l];
    for(int i=l+1;i<=r;i++) {
        sum=sum^a[i];
    }
    if(sum==k)
        return true;
    return false;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int c=0;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            if(is_(i,j)){
                c++;
                b[c].l=i;
                b[c].r=j;
            }
        }
    }

    //for(int i=2;i<c;i++) {
    //    if(b[i].r<=b[i+1].r)
    //        continue;
    //    ans++;
    //}
    cout<<c;
    return 0;
}
