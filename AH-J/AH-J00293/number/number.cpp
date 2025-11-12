#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ss;
	cin>>s;
	int len1=s.size();
	for(int i=0;i<len1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss+=s[i];
		}
	}
	int len=ss.size();
	for(int i=0;i<len;i++){
		a[i]=ss[i]-'0';
	}
	sort(a,a+len);
	for(int i=len-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
