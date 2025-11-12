#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen(number.in,"r,stdin");
	freopen(number.out,"w,stdout");
	string s;
	cin>>s;
	int j=s.size();
	vector<int>a(s.size()+1);
	for(int i=1;i<=j;i++){
		a[i]=s[i-1]-'0';
	}
	sort(a.begin(),a.end());
	for(int i=s.size();i>=1;i--){
		if(a[i]<=9) cout<<a[i];
	}
	return 0;
}
