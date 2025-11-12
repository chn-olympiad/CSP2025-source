#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int len;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[++len]=s[i]-'0';
        }
    }
    sort(a+1,a+len+1,cmp);
    for(int i=1;i<=len;i++){
        cout<<a[i];
    }
    return 0;
}
