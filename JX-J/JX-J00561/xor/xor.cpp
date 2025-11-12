#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,z,a[N],t[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if (a[i]==k) z++;
    }
    for (int i=1;i<=n;i++){
        if (a[i]!=k){
            int x=a[i];
            for (int j=i+1;j<=n;j++){
                if (a[j]==k) break;
                x^=a[j];
                if (x==k){
                    t[i]=j;
                    break;
                }
            }
        }
    }
    int idx=1;
    for (int i=1;i<=n;i++){
        if (t[i] && i>=idx){
            int h=0;
            for (int j=i+1;j<=t[i];j++)
                if (t[j]) h++;
            if (h<2){
                z++;
                idx=t[i]+1;
            }
        }
    }
    cout<<z;
    return 0;
}
