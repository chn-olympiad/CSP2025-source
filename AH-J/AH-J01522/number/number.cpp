#include<bits/stdc++.h>
using namespace std;
int a[1000010],m,l;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i]-'0';
			m++;
		}
	}
	sort(a,a+m);
	for(int i=m-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;
	return 0;
}
