#include <bits/stdc++.h>
using namespace std;
int a[1000010],l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1);
	if(a[l]==0){
		cout<<0;
	}
	for(int i=l;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
