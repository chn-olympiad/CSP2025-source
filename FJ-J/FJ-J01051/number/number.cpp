#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;

string s;
int a[N],len;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=1;i<=l;i++){
		if(isdigit(s[i])) a[++len]=s[i]-'0';
	}
	sort(a+1,a+1+len,greater<int>());
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}
	return 0;
}
