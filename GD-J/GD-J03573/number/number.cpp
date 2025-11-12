#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int t=c-'0';
			a[++len]=t;
		}
	}
	sort(a+1,a+len+1,greater<int>());
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}
	return 0;
} 
