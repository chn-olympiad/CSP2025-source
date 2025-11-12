#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int d[100005];
    int ds=0;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            d[ds]=s[i]-'0';
            ds++;
        }

    }sort(d,d+ds);

    for(int i=ds-1;i>=0;i--){
        cout<<d[i];

    }




    fclose(stdin);
    fclose(stdout);
    return 0;
}

