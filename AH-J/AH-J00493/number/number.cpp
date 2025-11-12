#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
string s;
stack<int> z;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        int t=int(s[i])-48;
        if(0<=t&&t<=9) z.push(t);
    }
    int n[z.size()];
    int siz=z.size();
    for(int i=0;i<siz;i++){
        n[i]=z.top();
        z.pop();
    }
    sort(n,n+siz);
    for(int i=siz-1;i>=0;i--) cout<<n[i];
}
