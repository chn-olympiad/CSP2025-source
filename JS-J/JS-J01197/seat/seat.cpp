#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int k=n*m;
    int cnt=0;
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);
        if(a[i]>=a[1])cnt++;
    }
    int l1=cnt/(2*n)*2+1,l2=cnt%(2*n);
    if(l2==0)l1--,l2++;
    if(l2<=n)printf("%d %d",l1,l2);
    else {
        l2=2*n-l2+1;
        l1++;
        printf("%d %d",l1,l2);
    }
    return 0;
}
