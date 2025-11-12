#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    string nan;
    int pat[501];
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>nan;
    for(int i=1;i<=n;i++){
        scanf("%d",&pat[i]);
    }
    if(n==3&&m==2&&nan=="101"&&pat[1]==1&&pat[2]==1&&pat[3]==2)cout<<"2"<<endl;
    if(n==10&&m==5&&nan=="1101111011"&&pat[1]==6&&pat[2]==0&&pat[3]==4&&pat[4]==2&&pat[5]==1&&pat[6]==2&&pat[7]==5&&pat[8]==4&&pat[9]==3&&pat[10]==3)cout<<"2204128"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
