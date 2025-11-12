#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size(),l=0;
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&'9'>=s[i]){
			l++;
			a[l]=s[i]-48;
		}
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 