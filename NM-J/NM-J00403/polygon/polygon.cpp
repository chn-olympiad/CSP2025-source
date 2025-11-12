#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n=0;
int a[5000]={0};
int num=0;//fangfashu

int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){//put in
        cin>>a[i];
    }



    int t;
    for(int i=n-1;i>0;i--){//paixu
        if(a[i]>a[i-1]){
            t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
        }
    }


    int dist;//the whole distance of polygon
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){//number of jiashu

            for(int k=j+1;k<n;k++){//number of space
                dist=a[i]+a[j];
                for(int l=k;l<n;l++){
                    dist+=a[l];
                }
                if(dist>2*a[0]){
                    num++;
                }
            }
        }
    }
    cout<<num%998244353;
    return 0;
}
