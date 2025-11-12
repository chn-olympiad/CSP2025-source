#include<bits/stdc++.h>
using namespace std;
string s;
int n,sum=0,ci=0,cj=0;
bool f=false;
bool t=false;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    getline(cin,s);
    int len=s.size();
	if(len==1) cout<<s;
          else{
		             for(int i=1;i<=n;i++)
                     {
		              for(int j=1;j<=i;j++)
		              { 
		                   ci=s[i];
		                   cj=s[j];
				           if((s[i]=='1')&&(s[i]=='2')&&(s[i]=='3')&&(s[i]=='4')&&(s[i]=='5')&&(s[i]=='6')&&(s[i]=='7')&&(s[i]=='8')&&(s[i]=='9')) f=true;
				                                                                                                                              else continue; 
			               if((s[j]=='1')&&(s[j]=='2')&&(s[j]=='3')&&(s[j]=='4')&&(s[j]=='5')&&(s[j]=='6')&&(s[j]=='7')&&(s[j]=='8')&&(s[j]=='9')) t=true;
				                                                                                                                              else continue;
			               if((f==true)||(t=true)) 
			               {
			 	                if(s[i]>s[j]) sum=sum+ci*10+cj;
			 	                         else if(s[i]<s[j]) sum=sum+cj*10+ci;
		
			               }
		              }
                    }
              cout<<sum;
	         }
	fclose(stdin);
	fclose(stdout);
    return 0;
}
