#include<bits/stdc++.h>
using namespace std;
int n,m,num,poss,posx,posy;
int a[110];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
        if (i==1)
            num=a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for (int i=1;i<=n*m;i++){
        if (a[i]==num){
            poss=i;
            break;
        }
    }
    for (int i=1;i<=m;i++){
        if (poss>n)
            poss-=n;
        else{
            posx=i;
            posy=poss;
            break;
        }
    }
    if (posx%2==0)
        cout<<posx<<" "<<n+1-posy;
    else
        cout<<posx<<" "<<posy;
    return 0;
}
