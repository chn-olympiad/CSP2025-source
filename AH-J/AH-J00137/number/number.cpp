#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int c,a[1000005];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
            c++;
            a[c]=s[i]-'0';
        }
    }
    sort(a+1,a+c+1,cmp);
    for(int i=1;i<=c;i++){
        cout<<a[i];
    }
    return 0;
}
