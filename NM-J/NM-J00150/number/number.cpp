#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[s.size()],m=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[m]=s[i]-'0';
			m++;
		}
	}
	long long b[m];
	for(int i=0;i<m;i++){
		b[i]=a[i];
	}
	long long huge=0;
	for(int i=0;i<m;i++){
		sort(b,b+m);
		huge=huge*10+b[m-1];
		b[m-1]=INT_MIN;
	}
	cout<<huge;
	return 0;
}
