#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long p=1000001,s,b,c=0,r,max1;
    long long a[1000001];
    cin>>s;
    b=s%10;
    c=s%10;
    if(s==0)cout<<0;
    if(s==1)cout<<1;
    if(s==2)cout<<2;
    if(s==3)cout<<3;
    if(s==4)cout<<4;
    if(s==5)cout<<5;
    if(s==6)cout<<6;
    if(s==7)cout<<7;
    if(s==8)cout<<8;
    if(s==9)cout<<9;
    if(s==10)cout<<10;
    b=s%10;
    for(int i=0;i<=1000000000000000000;i++){
        r++;
        c=s/10;
        a[i]=c;
        s=s/10;
        if(s==0){
            break;
        }


        max1=a[0];
        for(int i=0;i<r;i++){
            if(max1<a[i]){
                max1=a[i];
                a[i]=0;
            }
            cout<<max1;
            max1=a[i+1];



        }


    }
    cout<<b;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
