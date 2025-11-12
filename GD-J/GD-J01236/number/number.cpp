#include<bits/stdc++.h>
using namespace std;
long long a[1000006],c;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9') a[++c]=s[i]-'0';
	sort(a+1,a+c+1);
	if(a[c]==0) printf("%d",0);
	else 
	 	for(int i=c;i>=1;i--)
	    	printf("%lld",a[i]);
	return 0;
}
