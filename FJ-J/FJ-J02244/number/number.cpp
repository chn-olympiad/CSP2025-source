#include<bits/stdc++.h>
using namespace std;
int num=0;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-48>=0&&s[i]-48<=9){
			a[++num]=s[i]-48;
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
