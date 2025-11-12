#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}
