#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int tot=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if((s[i]>=48)&&(s[i]<=57)) a[++tot]=s[i];
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--) cout<<a[i];
	return 0;
} 
