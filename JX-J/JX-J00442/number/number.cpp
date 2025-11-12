#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++n]=s[i]-'0';
        }
    }
    sort(a+1,a+1+n);
    while(n){
        cout<<a[n];
        n--;
    }
    return 0;
}
