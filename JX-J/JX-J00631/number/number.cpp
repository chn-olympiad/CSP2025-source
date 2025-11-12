#include <bits/stdc++.h>
using namespace std;
int a[1000010],gs;
string s;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            gs++;
            a[gs] = s[i]-'0';
        }
    }
    sort(a,a+gs+1,cmp);
    for(int i=0;i<gs;i++){
        cout<<a[i];
    }
    return 0;
}
