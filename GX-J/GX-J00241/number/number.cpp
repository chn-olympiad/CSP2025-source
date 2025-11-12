#include<bits/stdc++.h>
using namespace std;
int syx[1000];
long long n,m;
string xx;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,xx);
    n=xx.size();
    for(long long i=0;i<=n-1;i++){
        if(xx[i]>='0'&&xx[i]<='9'){
            m=xx[i];
            syx[m-48]++;
        }
    }
    for(long long i=9;i>=0;i--){
        if(syx[i]!=0){
            while(syx[i]!=0){
                cout<<i;
                syx[i]--;
            }
        }

    }


    return 0;
}
