#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[1]) sum++;
    }
    sum++;
    int lie=ceil(sum*1.0/n);
    if(lie==0) lie=n;
    int hang;
    if(lie%2==1){
        hang=sum%n;
    }
    else{
        hang=(n-sum%n)+1;
    }
    if(hang==0) hang=n;
    printf("%d %d",lie,hang);
    return 0;
}
