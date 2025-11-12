#include<bits/stdc++.h>
using namespace std;
bool fuck(int x,int y)
 {
  return x>y;	
 }
string s;
int he,ans;
int main()
{
 freopen("number.in","r", stdin); 
 freopen("number.out","w",stdout); 
 cin>>s;
 long long len=s.size();
 if(len==1)cout<<s;
 else if(len<=1e5)
       {
        sort(s.begin(),s.end(),fuck);
   	    for(int i=0;i<=len;i++)
   	     {
   	      if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')	
   	      he++;	
		 }
	    ans=len-he;
		for(int i=ans;i<=len;i++)
		 cout<<s[i];	
	   } 
 fclose(stdin);
 fclose(stdout);
 return 0;
} 

