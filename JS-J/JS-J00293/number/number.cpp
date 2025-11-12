#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,greater<int>());
    for(int i=1; i<=cnt; i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
