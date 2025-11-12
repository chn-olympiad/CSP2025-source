#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int pos=0;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') a[++pos]=int(s[i]-'0');
	sort(a+1,a+pos+1);
	if(a[pos]==0){
		cout<<'0';
		return 0;
	}
	for(int i=pos;i>=1;i--)
		printf("%d",a[i]);
	return 0;
}
