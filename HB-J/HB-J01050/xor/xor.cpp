#include<bits/stdc++.h>
using namespace std;
int n,k;
void teshuA(){
    cout<<n/2;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    bool isA=true,isB=true;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]!=1)isA=false;
    }
    if(isA)teshuA();
    else{
        if(k==0){
            int cnta=0,cntb=0;
            for(int i=0;i<n-1;i+=2){
                if(a[i]==a[i+1])cnta++;
            }
            for(int i=1;i<n-1;i+=2){
                if(a[i]==a[i+1])cntb++;
            }
            cout<<max(cnta,cntb);
        }
        if(k==1){
            int cnta=0,cntb=0;
            for(int i=0;i<n-1;i+=2){
                if(a[i]!=a[i+1])cnta++;
            }
            for(int i=1;i<n-1;i+=2){
                if(a[i]!=a[i+1])cntb++;
            }
            cout<<max(cnta,cntb);

        }
    }
    return 0;
}
