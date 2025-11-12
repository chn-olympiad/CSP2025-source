#include<bits/stdc++.h>
using namespace std;
long long a[1000009],m;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
    for(int i=0;i<s.size();i++)	{
		if(s[i]>='0'&&s[i]<='9'){
			m++;
			a[m]=s[i]-'0';
		}
	}
	sort(a+1,a+1+m);
	for(int i=m;i>=1;i--){
		cout<<a[i];
	}
	
	return 0;
}