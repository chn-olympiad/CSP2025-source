#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int l[1000005];
    long long n=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            l[n]=s[i]-'0';
            n++;
        }
    }
    long long ss=s.size();
    sort(l,l+n);
    for(int i=n-1;i>=0;i--){
        cout<<l[i];
    }
    return 0;
}
