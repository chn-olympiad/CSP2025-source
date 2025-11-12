#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10005],c=1;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;++i){
		if('0'<=s[i]&&'9'>=s[i]){
			a[c++]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<c;++i){
		cout<<a[i];
	}
	return 0;
}
