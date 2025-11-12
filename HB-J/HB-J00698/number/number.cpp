#include<bits/stdc++.h>
using namespace std;
string s; 
int a[100005],ans=1;
int main()
{
  freopen("number.out","r",stdin);
  freopen("number.in","w",stdout);
  cin>>s;
  for(int i=0;i<s.size();i++)
  {
     int k=int(s[i]);
     if(48<=k && k<=57)
     { 
		 a[ans]=k-48;
		 ans++;
	 }
  }
  ans=ans-1;
  sort(a+1,a+1+ans);
  if(a[ans]==0)
  {
	 cout<<0<<endl;
	 return 0;
  } 
  for(int i=ans;i>=1;i--)
  {
	 cout<<a[i];
  }
	 
  return 0;
}
