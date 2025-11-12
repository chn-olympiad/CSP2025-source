#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
const int N=15;
int a[N];
bool cmp(int x,int y){return x>y;}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int s=a[1],idx;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            idx=i;
            break;
        }
    }
    if(idx%n==0){
        if((idx/n)%2==0){
            printf("%d %d\n",idx/n,1);
        }
        else{
            printf("%d %d\n",idx/n,n);
        }
    }
    else if((idx/n)%2==0){
        printf("%d %d\n",idx/n+1,idx%n);
    }
    else printf("%d %d\n",idx/n+1,n-idx%n+1);
    return 0;
}
