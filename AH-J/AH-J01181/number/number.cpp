#include<bits/stdc++.h>
using namespace std;
string st;
int a[1000010],k=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>st;
    for(int i=0;i<st.size();i++)
      if(st[i]<='9' and st[i]>='0')a[++k]=st[i]-'0';
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--)
      cout<<a[i];
    return 0;
}
