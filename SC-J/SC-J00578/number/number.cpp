#include<bits/stdc++.h>
using namespace std;
int a[1000020];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string s;
	cin>>s;
	int l=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>=0){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=l;i++){
		cout<<a[i];
	}
	return 0;
} 