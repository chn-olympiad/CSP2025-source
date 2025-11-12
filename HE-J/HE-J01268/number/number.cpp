#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int a[N],top;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			a[++top]=s[i]-'0';
		}
	}
	sort(a+1,a+top+1,greater<int>());
	if(a[1]==0) cout<<0;
	else{
		for(int i=1;i<=top;i++){
			printf("%d",a[i]);
		}
	}
	return 0;
}
