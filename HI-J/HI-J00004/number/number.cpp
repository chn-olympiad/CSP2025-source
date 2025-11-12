#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N];
int emp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int number=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[number++] = s[i]-'0';
		}
	}
	number--;
	sort(a+1,a+number+1,emp);
	for(int i=1;i<=number;i++){
		cout<<a[i];
	}
	
	return 0;
}
