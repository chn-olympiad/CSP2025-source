#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int z;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>'0'&&s[i]<='9'){
            a[i]=s[i]-'0';
        }
        if(s[i]=='0'){
            z++;
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        if(a[i]!=0){
            cout<<a[i];
        }
    }
    for(int i=1;i<=z;i++){
        cout<<0;
    }
    return 0;
}
