#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i] && s[i]<='9')
			a[++l]=s[i]-'0';
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--)
		cout<<a[i];
	puts("");
}
