#include<bits/stdc++.h>
using namespace std;
string s,y;
int a[100100];
bool bmp(int x,int y)
{
	return x>y;
}
int main()
 {
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     cin>>s;
     int len=s.size();
     if(len==1){cout<<s;return 0;}
           else {
                   for(int i=0;i<=len-1;i++)
                   {
					   y=s;
					   int sum=0,ans=0;
					   if(y[i]>='1'&&y[i]<='9')
					   for(int j=0;j<=i-1;j++)
                       {
						   sum++;
						   if(y[i]<y[j])swap(y[i],y[j]);
						   for(int i=0;i<=sum;i++)cout<<y;
						   break;
					   }
                       if(y[i]>='a'&&y[i]<='z')
                       {
						   ans++;
						   for(int j=0;j<=i-1;j++)
						   if(y[i]<y[i+1]) swap(y[i],y[i+1]);
						   cout<<y;
						   break;
					   }
                   }
                }
     fclose(stdin);
     fclose(stdout);
     return 0;
 }
