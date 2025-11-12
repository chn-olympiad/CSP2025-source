#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    string s;
    cin>>s;
    int n;
    int t=0;
    for(int i=0;i<s.size();i++){
        n=s[i]-'0';
        if(0<=n&&n<=9){
        a[i]=n;
        t++;
        }
    }
    sort(a,a+s.size());
    n=s.size()-1;
    for(int i=0;i<t;i++){
        cout<<a[n];
        n--;
    }
    return 0;
}
