#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;//'1'=49,'9'=57
    cin>>a;
    long long numwei=0,jinwei=1;
    long long c[100001]={0};
    long long d[100001]={0};
    long long b=a.length();
    for(int i=0;i<b;i++){
        if(int(a[i])>47){
            if(int(a[i])<58){
                c[i]=int(a[i]-48);
                numwei++;
            }
        }
    }
    long long max1=0,maxwei=0;
    for(int i=0;i<b;i++){
        for(int j=0;j<b;j++){
            if(c[j]>max1){
                max1=c[j];
                maxwei=j;
            }
        }
       d[i]=max1;
       c[maxwei]=0;
       max1=0;
    }
    long long s=0;
    for(int i=numwei-1;i>-1;i--){
        s=s+d[i]*jinwei;
        jinwei=jinwei*10;
    }
    cout<<s;
    return 0;

}
