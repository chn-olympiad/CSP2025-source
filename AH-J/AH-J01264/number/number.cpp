#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+78;
int n[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            n[j]=s[i]-48;
            j++;
        }
    }
    sort(n,n+j);
    for(int i=j-1;i>=0;i--) cout<<n[i];
    return 0;
}
