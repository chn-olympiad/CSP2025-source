#include<bits/stdc++.h>
using namespace std;
char s[10086];
int a[10086];
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.ans","w",stdout);
  int j=0;
  scanf("%s",s);
  for (int i=0;i<strlen(s);i++)
  {
      if (s[i]>='0' && s[i]<='9')
      {
          a[j]=s[i]-'0';
          j++;
      }
  }
  for (int i=0;i<j-1;i++)
    if (a[i]<a[i+1])
      swap(a[i],a[i+1]);
  for (int i=0;i<j;i++)
    cout<<a[i];
  fclose(stdin);
  fclose(stdout);
  return 0;
}
