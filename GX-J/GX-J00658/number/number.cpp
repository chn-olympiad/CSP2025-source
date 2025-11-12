#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[1000000]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' and s[i]<='9')
			a[t++] = s[i]-'0';
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
