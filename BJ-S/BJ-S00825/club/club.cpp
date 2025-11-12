#include<iostream>
#include<stdio.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    long long summ1=0;
    long long summ2=0;
    for(long long i=0;i<t;i++){
    long long n;
    cin>>n;
    long long ans;
    for(long long o=0;o<2;o++){
            long long sum=0,aa=0;
        for(long long u=0;u<3;u++){
                bool mm=1;
        cin>>sum;
        if(sum>aa){
            aa=sum;
        if(mm){
            o-=1;
            mm=0;
        }
        }
    }
    ans+=aa;
    }
    cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
