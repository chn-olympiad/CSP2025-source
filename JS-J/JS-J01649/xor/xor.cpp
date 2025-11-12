#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    int n,k,total=0;
    freopen("xor.in","r",stdin);
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int fin=n,start=1,tot=0,num=0,r=0;
    for(;start<n;){
        for(int pin=start;start<=fin;start++){
            pin==start;
            for(;pin<=fin;pin++){
                if(tot==0){
                    num=a[pin];
                    tot=1;
                }
                else{
                    num=(num^a[pin]);
                }
                if(num==k){
                    r=1;
                    fin=min(pin,fin);
                }
            }
            tot=0;
        }
        if(r){
            total++;
            start=fin+1;
            fin=n;
            num=0;
            r=0;
        }
        else{
            break;
        }
    }
    freopen("xor.out","w",stdout);
    cout<<total;
}
