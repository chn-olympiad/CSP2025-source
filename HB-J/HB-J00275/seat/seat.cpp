#include<bits/stdc++.h>
using namespace std;

int a[101];

bool cmp(int A,int B){
    return A>B;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%d",&a[1]);
    int R=a[1];
    for(int i=2;i<=n*m;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n*m+1,cmp);
    int l;
    for(l=1;l<=n*m;l++)
        if(a[l]==R)
            break;
    if(l%n==0){
        if(l/n%2==0)
            printf("1 %d",l/n);
        else
            printf("%d %d",l/n,n);
    }
    else{
        if((l/n+1)%2==0)
            printf("%d %d",l/n+1,n-l%n+1);
        else
            printf("%d %d",l/n+1,l%n);
    }
    return 0;
}
