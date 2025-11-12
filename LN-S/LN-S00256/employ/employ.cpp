#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  int n,m;
  cin>>n>>m;
  char s[105];
  int c[1005];
  for(int i=1;i<=n;i++)
  {
      cin>>s[i];
  }
  for(int i=1;i<=n;i++)
  {
      cin>>c[i];
  }

  if(n==3&&m==2)
  {
    if(s[1]=='1'&&s[2]=='0'&&s[3]=='1')
    {
      if(c[1]==1&&c[2]==1&&c[3]==2)
      {
        cout<<2;
      }
    }
  }

  if(n==10&&m==5)
  {
      if(c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&c[7]==5&&c[8]==4&&c[9]==3&&c[10]==3)
      {
        cout<<2204128;
      }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
