#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],R,Ri,c,r;

bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            Ri=i;
            break;
        }
    }
    if(Ri%n!=0){
        c=Ri/n+1;
        if((Ri/n)%2==1){
            r=n-((Ri-1)%n);
        }
        else{
            r=Ri%n;
        }
    }
    else{
        c=Ri/n;
        r=n;
    }

    printf("%d %d",c,r);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
