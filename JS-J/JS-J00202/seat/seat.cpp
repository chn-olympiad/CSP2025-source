#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,ans[15][15],arr[105],lzqtql,candybartql,curc=1,curr=1,d=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    candybartql=n*m;
    for (int i=1;i<=candybartql;++i){scanf("%d",arr+i);}
    lzqtql=arr[1];
    sort(arr+1,arr+1+candybartql,greater<int>());
    for (int i=1;i<=candybartql;++i){
        if (curr>n){curr=n;d=-1;++curc;}
        if (!curr){curr=1;d=1;++curc;}
        if (arr[i]==lzqtql){printf("%d %d\n",curc,curr);return 0;}
        curr+=d;
    }
    return 0;
}
