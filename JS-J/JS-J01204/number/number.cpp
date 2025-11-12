#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[10]={0};
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    bool f=0;
    for(int i=1;i<10;i++){
        if(a[i]>0){
            f=1;
            break;
        }
    }
    if(f==0){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;){
        if(a[i]>0){
            cout<<i;
            a[i]--;
        }else{
            i--;
        }
    }
    return 0;
}
