#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=0;
	cin>>s;
	char b[s.length()+5];
	for(int i=0;i<s.length();i++){
		if(s[i]>=48&&s[i]<=57)
		{
			b[j]=s[i];
			j++;
		}
	}
	for(int i=j-1;i>0;i--){
		for(int t=0;t<i;t++){
	  	if(b[t]<b[t+1])swap(b[t],b[t+1]);
	  }
	}
	 for(int i=0;i<j;i++)
	 cout<<b[i];
	fclose(stdin);
	fclose(stdout);
	  return 0;
}
