#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,val,id=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&val);
    int k=n*m-1;
    for(int i=1;i<=k;i++){
        int x;
        scanf("%d",&x);
        if(x>val)id++;
    }
    int i=(id/n)+1,j=id%n;
    //printf("%d\n",id);
    if(i%2==0){
        if(j!=0)printf("%d %d\n",i,n-j+1);
        else printf("%d %d\n",i-1,n);
    }
    else{
        if(j!=0)printf("%d %d\n",i,j);
        else printf("%d %d\n",i-1,1);
    }
    return 0;
}
