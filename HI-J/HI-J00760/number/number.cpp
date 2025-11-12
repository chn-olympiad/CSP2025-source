#include<bits/stdc++.h>
using namespace std;
string s;
int a[10010],l,g=0,ma=-1e9;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
 	cin>>s;
 	l=s.size();
 	for(int i=0;i<l;i++)
 	{
 		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
 		{
 			a[g]=int(s[i])-48;
			g+=1;
		 }
	 }
	for(int i=0;i<g;i++)
		{
			for(int j=i+1;j<=g;j++)
			{
				if(a[j]>ma)
				ma=j;
			}
			if(a[ma]>a[i])swap(a[i],a[ma]);
			ma=-1e9;
		}
	for(int i=0;i<g;i++)
		{
			cout<<a[i];
		}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
