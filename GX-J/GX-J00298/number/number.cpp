#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main (){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long a[10000];
    long long sum=0;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            sum=s[i]-48;
            a[sum]=sum;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]!=0){
            cout << a[i];
        }
    }
    return 0;
}
