#include<bits/stdc++.h>
using namespace std;
const int n=100000086;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    string s;
    int a[n];
    cin>>s;
    int xb=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
            xb++;
        }
    }
    for(int i=0;i<xb;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
            }
    }
    for(int i=0;i<xb;i++){
            cout<<a[i];
    }
    return 0;
}
