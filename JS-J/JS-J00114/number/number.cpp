#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int a[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int k=0;
    for(int i=0;i<s.length();i++){
        if(s[i]<='9'&&s[i]>='0'){
             a[++k]=s[i]-'0';
        }
    }
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++) cout<<a[i];
    return 0;
}
