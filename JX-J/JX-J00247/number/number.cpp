#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int idx;
int a[N];
string s;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[++idx]=s[i]-'0';
    }
    sort(a+1,a+1+idx,cmp);
    for(int i=1;i<=idx;i++) cout<<a[i];
    return 0;
}
