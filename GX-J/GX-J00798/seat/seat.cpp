#include<bits/stdc++.h>
using namespace std;
//WC!WoWangLeJieGongTiZenMeXieLe!!
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;//n:Hang m:Lie
    cin>>n>>m;
    int b,d;
    int c[n*m+5];
    for(int i=1;i<=n*m;i++){
        cin>>c[i];
        b=c[1];
        d=b;
    }
    sort(c+1,c+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
            //cout<<c[i]<<endl;//TSJDS!!!!!!!!!!
        if(c[i]==b) {
                b=i;
                break;
        }
    }
    //cout<<"hhhhh"<<b<<endl;//TSJDS!!!!!!!!!!
    if(n==1&&m==1) {
        cout<<1<<' '<<1;
        return 0;
    }
    if((b+1)/n%2!=0){//XiangXia
        if(b%n!=0) cout<<b/n+1<<' ';//sc Lie
        else cout<<b/n<<' ';
        if(b%n==0)cout<<n;//sc Hang
        else cout<<b%n;//cout<<b<<"tiaoshi";
    }else{//XiangShang
        if(b%n!=0) cout<<b/n+1<<' ';//sc Lie
        else cout<<b/n<<' ';
        if(b%n==0)cout<<1;//sc Hang
        else cout<<n-b%n+1;
    }
    return 0;
}
