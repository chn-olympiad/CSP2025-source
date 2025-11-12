#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int p=0;
	for(int i=0;i < (int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++p]=s[i]-'0';
		}
	}
	sort(a+1,a+p+1,greater<int>());
	for(int i=1;i <= p;i++){
		cout<<a[i];
	}
	return 0;
}