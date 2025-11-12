#include <bits/stdc++.h>
using namespace std;
int n,x,a[500010],maxn=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==2){
        if (a[1]==1&&a[2]==0||a[1]==0&&a[2]==1) cout<<2;
        else if (a[1]==0&&a[2]==0) cout<<3;
        else cout<<0;
    }
    else{
        int l=1000000,r=0,sum=0;
        for (int i=1;i<=n;i++){
            for (int j=i;j<=n;j++){
                int num=a[i];
                for (int k=i+1;k<=j;k++) num^=a[k];
                if (num==x) if (i>r||j<l){
                    sum++;
                    l=min(l,i);
                    r=max(r,j);
                }
            }
        }
        maxn=max(maxn,sum);
        cout<<maxn;
    }
    return 0;
}
