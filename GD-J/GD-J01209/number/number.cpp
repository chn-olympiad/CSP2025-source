#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n,i=0,a[1000001],j=1;
    n=s.size();
    while(i<n)
    {
        while(s[i]<'0'||s[i]>'9'&&i<n)
        {
            i++;
        }
        while(s[i]>='0'&&s[i]<='9'&&i<n)
        {
            a[j]=s[i]-'0';
            j++;
            i++;
        }
    }
    j--;
    sort(a+1,a+1+j);
    for(int i=j;i>=1;i--)
    {
        cout<<a[i];
    }

    return 0;
}
