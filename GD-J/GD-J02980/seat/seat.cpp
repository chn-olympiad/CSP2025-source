#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
long long m,n,st,t,y,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>y;
    st=1;
    for(int i=2;i<=n*m;i++){
        cin>>t;
        if(t>y){
            st+=1;
        }
    }
    c=(st-1)/n+1;
    if(c%2==0){
        r=n-st%n+1;
    }else{
        r=(st-1)%n+1;
    }
    cout<<c<<' '<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
