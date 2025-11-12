#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
string s;
int a[N],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt++]=s[i]-'0';
            //cout<<a[i];
        }
    }
    sort(a,a+cnt);
    for(int i=cnt-1;i>=0;i--)cout<<a[i];
    return 0;
}
