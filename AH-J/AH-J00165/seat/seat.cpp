#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            r=i;
        }
    }
    int x,y;
    x=r/n;
    int yu=r%n;
    if(yu>0){
        x++;
    }
    if(x%2==0){
        y=(n-yu+1)%n;
        if(yu==0){
            y=1;
        }else if(yu==1){
            y=n;
        }
    }else{
        y=yu;
        if(y==0){
            y=n;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
