#include<bits/stdc++.h>
using namespace std;
string s;
int m,sum,n,x,y,maxx=-1111;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>n;
  if(n==1) cout<<"1"; 
   else if(n>=10||n<100) m=n%10;
          cout<<max(m*10+n/10,n); 
    // else cout<<max(max(m*100+n/100+x,n),x*100+m*10+n/100);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
/* if(s.size==1)cout<<"1";                                                      
    else x=s.size();                                                            
      for(int i=0;i<=x;i++) */                                                   
