#include<bits/stdc++.h>
using namespace std;
int main() {	
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
char s;
int a[100];
cin>>s;
int j=0;
while(1)
{
	if(s>='0' and s<='9')a[j]=s;
	j++;
}
sort(a,a+1,j);
cout<<a;
 return 0;
}

