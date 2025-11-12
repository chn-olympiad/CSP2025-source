#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,s[5005]={0};
    cin>>a;
    if(a<=3){
        cin>>s[1]>>s[2]>>s[3];
        if(s[1]+s[2]>s[3]&&s[2]+s[3]>s[1]&&s[1]+s[3]>s[2])
          cout<<"1";
        else
          cout<<"0";
    }
    return 0;
}

