#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int scorce,num;
    cin>>scorce;
    a[1]=scorce;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
            if(a[i]==scorce){
            num=i;
            break;
        }
    }
    int r=(num-1)/n+1;
    cout<<r<<" ";
    if(r%2==1) cout<<(num-1)%n+1;
    else cout<<n-((num-1)%n+1);
}
