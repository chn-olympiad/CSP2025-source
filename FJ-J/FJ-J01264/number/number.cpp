#include<bits/stdc++.h>
using namespace std;
int a[1000100],l=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[l]=s[i]-48;
			l++;
		}
	}
	sort(a+1,a+l);
	for(int i=l-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}