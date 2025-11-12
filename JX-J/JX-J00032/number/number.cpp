#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],b=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]*1-48<=9&&s[i]*1-48>=0){
            a[s[i]*1-48]=a[s[i]*1-48]+1;
        }
        if(s[i]*1-48>=b){
            b=s[i]*1-48;
        }
    }
    while(b!=-1){
        if(a[b]==0){
            b--;
        }
        else{
            cout<<b;
            a[b]--;
        }
    }
    return 0;
}
