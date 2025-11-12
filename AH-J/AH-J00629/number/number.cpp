#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);	
      
      string s;
      cin>>s;
      int a[100010],cnt=0;
      for(int i=0;i<s.size();i++)
      {
		  if(s[i]=='0')
		  {
			  cnt++;
			  a[cnt]=0;
		  }
		  else if(s[i]=='1')
		  {
			  cnt++;
			  a[cnt]=1;
		  }
		  else if(s[i]=='2')
		  {
			  cnt++;
			  a[cnt]=2;
		  }
		  else if(s[i]=='3')
		  {
			  cnt++;
			  a[cnt]=3;
		  }
		  else if(s[i]=='4')
		  {
			  cnt++;
			  a[cnt]=4;
		  }
		  else if(s[i]=='5')
		  {
			  cnt++;
			  a[cnt]=5;
		  }
		  else if(s[i]=='6')
		  {
			  cnt++;
			  a[cnt]=6;
		  }
		  else if(s[i]=='7')
		  {
			  cnt++;
			  a[cnt]=7;
		  }
		  else if(s[i]=='8')
		  {
			  cnt++;
			  a[cnt]=8;
		  }
		  else if(s[i]=='9')
		  {
			  cnt++;
			  a[cnt]=9;
		  }
		  else continue;
	  }
	  sort(a+1,a+cnt+1);
	  for(int i=cnt;i>=1;i--)
	  {
		  cout<<a[i];
	  }
      return 0;
}
