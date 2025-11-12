#include<bits/stdc++.h>
using namespace std;
char s[1000006];
long long b[105],p,u=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    while(cin>>s[u])u++;
     for(int i=0;i<u;i++)
     {
     	if(s[i]>='0'&&s[i]<='9')b[s[i]-'0']++;
	 }
	 for(int i=9;i>=0;i--)
	 {
	 	if(b[i]!=0)
	 	{
	 		for(int j=1;j<=b[i];j++)printf("%lld",i);
		}
	 }
	return 0;
} 
