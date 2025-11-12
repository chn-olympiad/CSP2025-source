#include<bits/stdc++.h>
using namespace std;
string s,ans;
char ch;
int a[1000010];

bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if('0'<=s[i]&&s[i]<='9') ans+=s[i];
    }
    for(int i=0;i<ans.length();i++){
        a[i]=ans[i]-'0';
    }
    sort(a,a+ans.length(),cmp);
    for(int i=0;i<ans.length();i++){
        cout<<a[i];
    }
    return 0;
}
