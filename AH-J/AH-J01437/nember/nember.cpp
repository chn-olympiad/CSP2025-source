#include<bits/stdc++.h>
using namespace std;
int b[1000000],sum;
long long t;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
      string a;
      cin>>a;
      for(int i=0;a[i]!='\0';i++)
      {
          if(a[i]<='9'&&a[i]>='0')
          {
              b[sum]=a[i]-'0';
               sum++;
          }

      }
      sort(b,b+sum,cmp);
      for(int i=0;i<sum;i++)
      {
          t=t*10+b[i];
      }
      cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
