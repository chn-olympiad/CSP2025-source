#include <bits/stdc++.h>
using namespace std;
long long a[10005],n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];

    }
    long long x=a[1];
    sort(a+1,a+n*m+1,cmp);
    long long xi=0;
    for(long long i=1;i<=n*m;i++){
        if(a[i]==x) xi=i;

    }
    if((xi/n)%2==0){
        if(xi%n==0){
            cout<<xi/n<<" "<<m;
        }else if(xi%m==1){
            cout<<xi/n+1<<" "<<xi%m;
        }
        else{
            cout<<xi/n+1<<" "<<xi%m;
        }
    }else{
        if(xi%n==0){
            cout<<xi/n<<" "<<m;
        }else if(xi%m==1){
            cout<<xi/n+1<<" "<<m;
        }else{
            cout<<xi/n+1<<" "<<xi%m;
        }
    }

    return 0;
}
