#include<bits/stdc++.h>
using namespace std;
int H,L,pos=0,n,m,lis,wei;
int num[110];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>L>>H;
    n=L*H;
    for(int i=1;i<=n;i++)cin>>num[i];
    m=num[1];
    sort(num+1,num+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(num[i]==m){
            pos=i;
            break;
        }
    }


    bool sign=pos%H;

    if(sign==0){
        lis=pos/H;
        if(lis%2==0)cout<<lis<<" "<<1;
        else cout<<lis<<" "<<H;
    }
    else{
        lis=pos/H+1;
        wei=pos%H;
        if(lis%2==0)cout<<lis<<" "<<(H-wei+1);
        else cout<<lis<<" "<<wei;
    }
    return 0;
}
