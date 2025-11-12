#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int t=1,num=0;
	cin>>s;
	int a[s.size()+1];
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	sort(a+1,a+t,greater<int>());
	for(int i=1;i<t;i++)
		num=num*10+a[i];
	cout<<num<<endl;
	return 0;
}
