#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],t=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=s[i]-'0';
		}
	}
	for(int i=1;i<t;i++){
		for(int j=i+1;j<=t;j++){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=t;i++)cout<<a[i];
	return 0;
}
