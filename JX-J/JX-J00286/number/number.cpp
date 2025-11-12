#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
const int N=1e6+5;
char a[N],k=0;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    IOS;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9') a[++k]=s[i];
    }
    sort(a+1,a+1+k,cmp);
    if(a[1]=='0'){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=k;i++) cout<<a[i];
    return 0;
}

