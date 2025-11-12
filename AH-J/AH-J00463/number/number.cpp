#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool comp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=0;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0' && s[i]<='9'){
            n++;
            a[n]=s[i]-'0';
        }
    }
    sort(a+1,a+n+1,comp);
    if(a[1]==0){
        cout<<0;
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<a[i];
        }
    }

    return 0;
}
