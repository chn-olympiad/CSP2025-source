#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i,j,a[100005];
    string s;
    cin>>s;
    j=0;
    for(i=0;i<s.size();i++){
       if(s[i]>=48&&s[i]<=57){
        a[j]=s[i]-48;
        j++;
       }
    }
    sort(a,a+j);
    for(i=j-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
