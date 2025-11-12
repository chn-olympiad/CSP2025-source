#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],b;
bool solve(const int &A,const int &B){
    return A>B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int num=n*m;
    for(int i=1;i<=num;i++)
        scanf("%d",&a[i]);
    b=a[1];
    sort(a+1,a+num+1,solve);
    int k=1;
    while(a[k]!=b){
        k++;
    }
    int z=k/n,y=k%n;
    if(y==0){
        if(z%2==0)
            printf("%d %d",z,1);
        else
            printf("%d %d",z,n);
    }
    else{
        if(z%2==0)
            printf("%d %d",z+1,y);
        else
            printf("%d %d",z+1,n-y+1);
    }
    return 0;
}
