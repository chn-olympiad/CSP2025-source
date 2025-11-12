#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],id;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;n=s.size();
    for(int i=0;i<n;i++)
        if(s[i]<='9'&&s[i]>='0')
            a[++id]=s[i]-'0';
    sort(a+1,a+id+1);
    for(int i=id;i>=1;i--)
        cout<<a[i];
    return 0;
}
