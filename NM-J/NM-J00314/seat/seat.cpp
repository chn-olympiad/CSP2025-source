#include<bits/stdc++.h>
using namespace std;
void seat(char *i,char *o){
    ios::sync_with_stdio(0);
    freopen(i,"r",stdin);
    freopen(o,"w",stdout);
    int m,n,xiaoR=0,h,l;
    cin>>m>>n;
    int kaochang[m*n];
    for(int i=0;i<m*n;i++)
        cin>>kaochang[i];
    for(int i0=1;i0<m*n;i0++){
        if(kaochang[i0]>=kaochang[0])
            xiaoR++;
    }
    l=xiaoR/n+1;
    (l%2==0)?h=n-xiaoR%n:h=xiaoR%n+1;
    cout<<l<<' '<<h<<' '<<xiaoR;
    fclose(stdin);
    fclose(stdout);
}
int main(){
    char i1[50]="/home/noi/seat/seat1.in",o1[50]="/home/noi/test/seat/seat1.out"i2[50]="/home/noi/seat/seat2.in",o2[50]="/home/noi/test/seat/seat2.out"i3[50]="/home/noi/seat/seat3.in",o3[50]="/home/noi/test/seat/seat3.out";
    seat(i1,o1);
    seat(i2,o2);
    seat(i2,o3);
    return 0;
}
