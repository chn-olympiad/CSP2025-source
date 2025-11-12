#include<bits/stdc++.h>
using namespace std;
const int N=1010000;
string s;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[c]=s[i]-'0';
            c+=1;
        }
    }
    sort(a,a+c);
    for(int i=0;i<c;i++){
        cout<<a[c-i-1];
    }
    return 0;
}
