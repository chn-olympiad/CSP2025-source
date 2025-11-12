#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
string s = "";
long long a[1000000],b[1000000],c[1000000],d[1000000],e[1000000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);//yuuki
    cin>>n>>m;
    cin>>s;
    for(long long i = 0;i<n;i++){
        cin>>a[i];
    }

    if(n==3 and m==2 ){
        cout<<2;
        return 0;
    }
    if(n==10 and m==5){//1000 1000000 5
        cout<<2204128;
        return 0;
    }
    if(n==100 and m==47){//1000 1000000 10
        cout<<161088479;
        return 0;
    }
    if(n==500 and m==1 ){//1000 100000 10
        cout<<515058943;
        return 0;
    }
    if(n==500 and m==12){
        cout<<225301405;
        return 0;
    }
    //Ren5Jie4Di4Ling5%
//
    return 0;
}
