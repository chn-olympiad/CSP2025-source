#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int a[15];
int cnt=0,ans=0;
int number(char x){
        if('0'<=x&&'9'>=x){
            return (x-'0');
            cnt++;
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int b=s.size();
    for(int i=0;i<b;i++){
        ans=number(s[i]);
        if(0<=ans&&9>=ans)
        a[ans]=a[ans]+1;
    }
    for(int i=9;i>=0;i--){
        if(a[i]!=0){
            while(a[i]--)
                cout<<i;
        }
    }
    return 0;
}
