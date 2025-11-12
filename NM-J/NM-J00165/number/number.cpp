#include <bits/stdc++.h>

using namespace std;

int a[1000005];

bool cmd(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int l=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[l] = s[i]-48;
            l++;
        }
    }
    sort(a,a+l,cmd);
    if(a[0]==0){
        cout<<0;
    }else{
        for(int i=0;i<l;i++){
            cout<<a[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
