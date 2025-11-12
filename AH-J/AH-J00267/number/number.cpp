#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  char s[1000007];
  int sn[1000007];
  int i=1;
  int j=1;
  int tmp[800007];
  while(cin>>s[i])
  {
	  sn[i]=s[i]-'0';
	  if(sn[i]>=0 and sn[i]<=9)
	  {
		  tmp[j]=sn[i];
		  j++;
	  }
	  i++;
  }
  sort(tmp+1,tmp+j+1);
  for(int k=j;k>1;k--)
  cout<<tmp[k];
  return 0;
}
