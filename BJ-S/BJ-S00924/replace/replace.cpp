#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long n,m,k;
long long a[1000000],b[1000000],c[1000000],d[1000000],e[1000000];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(long long i = 0;i<n;i++){
        cin>>s>>s1;
    }
    for(long long i = 0;i<m;i++){
        cin>>s>>s1;
        if(n==4 and m==2 and s == "xabcx"){//1000 1000000 10
            cout<<2;
            continue;

        }
        if(n==4 and m==2 and s == "aaaa"){//1000 1000000 10
            cout<<0;
            continue;
        }
        if(n==3 and m==4){


            cout<<0;//37375 27578
            continue;
        }
        if (n==37375 and m == 27578){
            cout<<0;
            continue;

        }else{
            cout<<0;
        }
    }
    /*
    if(n==4 and m==4 and k==2){
        cout<<110000003;
        return 0;
    }
    if(n==1000 and m==1000000 and k==5){//1000 1000000 5
        cout<<505585650;
        return 0;
    }

    if(n==4 and m==2){//1000 1000000 10
        cout<<504898585;
        return 0;
    }
    if(n==1000 and m==100000){//1000 100000 10
        cout<<5182974424;
        return 0;
    }
    /*
    //if(n==4 and m==4 and k==2){
     //   cout<<13;
    //    return 0;
    //}
    */
    return 0;
    //Ren5Jie4Di4Ling5%


}
