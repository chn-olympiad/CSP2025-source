#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],j;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a,a+j,cmp);
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
