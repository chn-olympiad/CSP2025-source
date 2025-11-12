#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool b(int a,int b){
    if(a>b) return true;
    else return false;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=0;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[n]=s[i]-'0';
            //cout<<a[n]<<s[i]<<endl;
            n++;
        }
    }
    sort(a,a+n,b);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
