#include<bits/stdc++.h>
using namespace std;
string s;
int p[1000005],num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(s[i]>='0'&&s[i]<='9')p[++num]=s[i]-'0';
	sort(p+1,p+1+num);
	if(p[num]==0)
	cout<<0;
	else{
		for(int i=num;i>=1;i--)
		cout<<p[i];
	}
	return 0;
}
