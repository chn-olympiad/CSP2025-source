#include <bits/stdc++.h>
using namespace std;
const int N=205;
int n,m,cnt;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&m,&n);
    int tot=n*m;
    for(int i=1;i<=tot;i++){
        scanf("%d",&a[i]);{
            if(a[i]>=a[1])cnt++;
        }
    }
    int l=(cnt-1)/m+1,r=cnt%m;
    if(r==0) r=m;
    if(l%2==0) r=m-r;
    if(r==0) r=m;
    printf("%d %d",l,r);
    return 0;
}
