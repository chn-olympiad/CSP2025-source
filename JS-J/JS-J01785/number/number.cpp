#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N];
int cnt;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string st;
    cin>>st;
    for(int i=0;i<st.size();i++){
        if(st[i]>='0'&&st[i]<='9')a[++cnt]=st[i]-'0';
    }
    sort(a+1,a+cnt+1,greater<int>());
    for(int i=1;i<=cnt;i++)cout<<a[i];
    cout<<endl;
    return 0;
}