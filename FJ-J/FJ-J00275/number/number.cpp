#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],l=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&'9'>=s[i]){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a+1,a+l);
	for(int i=l-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
