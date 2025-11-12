#include<bits/stdc++.h>
using namespace std;
int a[1145140],cnt,n,m;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')a[++cnt]=(s[i]-'0');
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
