#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	int len=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			len++;
			a[len]=s[i]-'0';
		}
	}
	sort(a+1,a+1+len,cmp);
	if(a[1]==0){
		printf("0");
		return 0;
	}
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}
	return 0;
}
