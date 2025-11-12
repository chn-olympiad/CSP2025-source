#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0,a[1000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i+1]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+1+s.size(),cmp);
	for(int i=1;i<=cnt;i++) printf("%d",a[i]);
	puts("");
	return 0;
}
