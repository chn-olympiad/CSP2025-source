#include<bits/stdc++.h>
using namespace std;
struct a{
    int x1;
    int x2;
    int x3;
}mantidu[100010],renshu[6]={0},duhe[6]={0};
int t,n,zonghe[100010];
int big(int a,int b,int c){
    int d=max(a,b);
    int f=max(d,c);
    return f;
}
int main(){
    freopen("clnb.in","r",stdin);
    freopen("clnb.out","w",stdout);
    cin>>t;
    for(int j=1;j<=t;j++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>mantidu[i].x1>>mantidu[i].x2>>mantidu[i].x3;
        }
        for(int i=1;i<=n;i++){
            if(big(mantidu[i].x1,mantidu[i].x2,mantidu[i].x3)==mantidu[i].x1){
                renshu[j].x1++;
                duhe[j].x1=mantidu[i].x1+duhe[j].x1;
            }
            else if(big(mantidu[i].x1,mantidu[i].x2,mantidu[i].x3)==mantidu[i].x2){
                renshu[j].x2++;
                duhe[j].x2=mantidu[i].x2+duhe[j].x2;
            }
            else if(big(mantidu[i].x1,mantidu[i].x2,mantidu[i].x3)==mantidu[i].x3){
                renshu[j].x3++;
                duhe[j].x3=mantidu[i].x2+duhe[j].x2;
            }

        }
        if(renshu[j].x1<(n/2)&&renshu[j].x2<(n/2)&&renshu[j].x3<(n%2)){
            zonghe[j]=duhe[j].x1+duhe[j].x2+duhe[j].x3;
        }
    }
    for(int i=1;i<=t;i++){
        cout<<zonghe[i]<<endl;
    }
    return 0;
}
