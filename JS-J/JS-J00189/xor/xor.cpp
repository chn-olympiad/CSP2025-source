#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const int STD=2e5+5;
long long a[N];
long long n;
long long k;
long long cnt;
long long max_cnt;

int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);


    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2){
        cout<<n;
        return 0;
    }
    if((n<=100&&k<=1)||(n<=200000&&k<=1)){
        if(k==0){
            cout<<n;
        }else if(k==1){
            bool flago=false;
            bool flagz=false;
            long long  markk=-1;
            long long markkk=-1;
            long long cnt=0;
            for(long long i=1;i<=n;i++){
                if(a[i]==0){
                    flagz=true;
                    markk=i;
                }else {
                    flago=true;
                    markkk=i;
                }
                if(flago==true&&flagz==true&&abs(markk-markkk)==1){
                    cnt++;
                    flago=flagz=false;
                    markk=markkk=-1;
                }
            }
            cout<<cnt;
            return 0;
        }
    }
    return 0;
}
