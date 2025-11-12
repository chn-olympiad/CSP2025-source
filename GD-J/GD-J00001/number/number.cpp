#include<bits/stdc++.h>
using namespace std;
int a[1005];
int flag=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=1;i--){
		for(int j=1;j<=a[i];j++)cout<<i;
		if(a[i]>=1)flag=0;
	}
	if(flag==0)for(int i=1;i<=a[0];i++)cout<<0;
	else cout<<0;
	return 0;
} 
