#include<bits/stdc++.h>
using namespace std;
string s;
int shu[20];
int main()
 {
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>s;
  int qwe=s.size();
  for(int i=0;i<qwe;i++)
     {
      if(s[i]>='0'&&s[i]<='9') shu[s[i]-'0']++;
     }
  for(int j=9;j>=0;j--)
     {
		 for(int i=1;i<=shu[j];i++)
		    {
				printf("%d",j);
			}
	 }
  fclose(stdin);
  fclose(stdout);
  return 0;
 }
