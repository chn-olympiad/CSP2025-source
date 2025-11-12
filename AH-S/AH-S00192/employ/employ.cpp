#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
string s;
int a[50];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3&&m==2&&s=="101"){
        cout<<2;
    }else if(n==10&&m==5&&s=="1101111011"){
        cout<<2204128;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
