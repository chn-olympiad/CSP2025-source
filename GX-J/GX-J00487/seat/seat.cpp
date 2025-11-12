#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b[110]={0},jsqn,jsqm,r,pd=0,ans;
    cin>>n>>m;
    int nm=n*m;
    for(int i=0;i<nm;i++){
        cin>>b[i];
    }
    r=b[0];
    sort(b,b+nm,cmp);
    for(int i=0;i<nm;i++){
        if(b[i]==r){
            ans=i;
            break;
        }
    }
    jsqm=ans/n+1;
    if((ans/n)%2==0) jsqn=ans%n+1;
    else if((ans/n)%2==1) jsqn=n-ans%n;
    cout<<jsqm<<' '<<jsqn<<endl;
    return 0;
}
