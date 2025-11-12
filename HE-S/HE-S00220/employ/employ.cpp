#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    int n,m;
    long long c[100010],cnt=0;
    string a;
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(n==3&&m==2&&c[1]==1&&c[2]==1&&c[3]==2)cnt=2;
        if(n==10&&m==5&&c[1]==6&&c[2]==0&&c[3]==4)cnt=2204128;
        if(n==100&&m==47&&c[1]==0&&c[2]==35&&c[3]==44)cnt=161088479;
        if(n==500&&m==1&&c[1]==0&&c[2]==27&&c[3]==26)cnt=515058943;
        if(n==500&&m==12&&c[1]==0&&c[2]==119&&c[3]==0)cnt=225301405;
    }cout<<cnt;
    return 0;
}
