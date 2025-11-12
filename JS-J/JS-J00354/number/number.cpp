#include<bits/stdc++.h>
using namespace std;
int z[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
string a;
cin>>a;
for(int i=0;i<a.size();i++)
{
  if(a[i]<='9'&&a[i]>='0')
  z[a[i]-'0']++;
}
for(int i=9;i>=0;i--)
{
      for(int j=0;j<z[i];j++)
      {
      cout<<i;
      }

}


}
