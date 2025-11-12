#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    int f=a[1];
    sort(a+1,a+k+1,cmp);
    int w;
    for(int i=1;i<=k;i++){
        if(a[i]==f){
            w=i-1;
            break;
        }
    }
    int ansn,ansm;
    ansm=w/n+1;
    int v=w%n;
    if(ansm%2==1){
        ansn=v+1;
    }
    else{
        ansn=n-v;
    }
    cout<<ansm<<' '<<ansn;
    return 0;
}
