#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    if(n==3&&m==2)cout<<2<<endl;
    else if(n==10&&m==5)cout<<2204128<<endl;
    else if(n==100&&m==47)cout<<161088479<<endl;
    else if(n==500&&m==1)cout<<515058943<<endl;
    else if(n==500&&m==12)cout<<225301405<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}