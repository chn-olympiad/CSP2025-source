#include<bits/stdc++.h>
using namespace std;
int n,m,c[105],a1,w;
bool cmp(int p,int q){
    return p>q;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1; c[1]=a1;
    for(int i=2;i<=n*m;i++){
        cin>>c[i];
    }
    sort(c+1,c+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(c[i]==a1){
            w=i; break;
        }
    }
    int flag=1,c=1,r=1;
    for(int i=2;i<=w;i++){
        if(flag==1){
            r++;
            if(r>=n) flag=2;
        }else if(flag==2){
            c++;
            if(r>=n) flag=3;
            else flag=1;
        }else if(flag==3){
            r--;
            if(r<=1) flag=2;
        }
    }
    cout<<c<<' '<<r;
}
