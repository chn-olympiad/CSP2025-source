#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.size()];
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[i]=int(s[i]-'0');
        }else{
            a[i]=-1;
        }
    }
    sort(a,a+s.size(),cmp);
    for(int i=0;i<s.size();i++){
        if(a[i]!=-1){
            cout<<a[i];
        }

    }
    return 0;
}
