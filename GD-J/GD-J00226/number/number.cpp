#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],A=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;++i)
		if(s[i]>='0'&&s[i]<='9') a[++A]=s[i]-'0';
	stable_sort(a+1,a+A+1,greater<int>());
	for(int i=1;i<=A;++i)
		cout<<a[i];
	return 0;
}
