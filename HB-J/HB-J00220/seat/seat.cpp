#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],len,t;
inline int erfen(int x){
    int l=1,r=len,mid,best=-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(a[mid]>=x){
            best=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return best;
}
inline bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    len=m*n;
    for(int i=1;i<=len;i++)scanf("%d",&a[i]);
    t=a[1];
    sort(a+1,a+len+1,cmp);
    int p=erfen(t);
    int lie=(p-1)/n+1;
    int s=(p-1)%n,hang;
    if(lie%2==1){
        hang=1+s;
    }else hang=n-s;
    printf("%d %d",lie,hang);
    return 0;
}
