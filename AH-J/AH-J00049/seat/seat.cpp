#include<bits/stdc++.h>
using namespace std;
int m,n,i,t,sc[105],rs,heng=0,shu=1,w;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>m>>n;
    t=m*n;
    for(i=1;i<=t;i++){
        cin>>sc[i];
        if(i==1) rs=sc[i];
    }
    sort(sc+1,sc+t+1,cmp);
    for(i=1;i<=t;i++){
        if(rs==sc[i]){
            w=i;
            break;
        }
    }
    for(i=1;i<=w;i++){
        if(shu%2==1) heng++;
        if(i%n==1&&i>n) shu++;
        if(shu%2==0) heng--;
    }
    cout<<shu<<' '<<heng;
    return 0;
}
