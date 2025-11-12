#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int qqq=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[qqq]=s[i]-'0';
			qqq++;
		}
	}
	sort(a,a+qqq);
	for(int i=qqq-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}