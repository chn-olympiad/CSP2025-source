#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6;
//define int long long
int a[SIZE],a_size,n,i;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
        if('0'<=s[i]&&s[i]<='9')
            a[a_size++]=s[i]^48;
    sort(a,a+a_size);
    for(i=a_size-1;i>=0;i--)
        cout<<a[i];
    cout<<endl;
    return 0;
}
