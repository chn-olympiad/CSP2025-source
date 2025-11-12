#include<bits/stdc++.h>
int a[105];
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m>>r;
    a[1]=r;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            if(i%n==0){
                if(i/n%2==0) printf("%d %d\n",i/n,1);
                else printf("%d %d\n",i/n,2);
            }
            else{
                if((i/n+1)%2==0) printf("%d %d\n",i/n+1,n-i%n+1);
                else printf("%d %d\n",i/n+1,i%n);
            }
        }
    }
    return 0;
}

