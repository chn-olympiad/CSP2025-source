#include<bits/stdc++.h>
using namespace std;
string s;
int a[7];
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    for(int i=1;i<=6;i++){
        cin>>s[i];
        if(s[i]>=0&&s[i]<=9){
            if(s[i]==0){
                a[i]=0;
            }
            if(s[i]==1){
                a[i]=1;
            }
            if(s[i]==2){
                a[i]=2;
            }
            if(s[i]==3){
                a[i]=3;
            }
            if(s[i]==4){
                a[i]=4;
            }
            if(s[i]==5){
                a[i]=5;
            }
            if(s[i]==6){
                a[i]=6;
            }
            if(s[i]==7){
                a[i]=7;
            }
            if(s[i]==8){
                a[i]=8;
            }else
            if(s[i]==9){
                a[i]=9;
            }
        }
    }
    sort(a+1,a+1+6);
    for(int i=1;i<=6;i++){
        cout<<a[i];
    }
return 0;
}
