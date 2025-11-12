#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],sl,j;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	sl=s.size();
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[++j]=s[i]-'0';
	sort(a+1,a+1+j);
	for(int i=j;i>=1;i--) printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
