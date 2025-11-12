#include<bits/stdc++.h>
using namespace std;
int a[11];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int e=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int t=s[i]-'0';
            a[t]++;
            if(t!=0) e=1;
        }
    }
    if(e==0) return 0;
    for(int i=9;i>=0;i--){
        for(int j=a[i];j>=1;j--){
            cout<<i;
        }
    }
    return 0;
}
