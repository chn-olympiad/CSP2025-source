#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
string str;
ll n,arr[maxn];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>str;
    for(int i=0;i<str.size();i++) if(str[i]>='0'&&str[i]<='9') arr[++n]=str[i]-'0';
    sort(arr+1,arr+1+n);
    for(int i=n;i>=1;i--) cout<<arr[i];
    return 0;
}
