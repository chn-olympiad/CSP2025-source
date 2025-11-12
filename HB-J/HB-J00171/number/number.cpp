#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000005],b[1000005];
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}
	}
	sort(a,a+s.size()+1);
	for(int i=0;i<=s.size();i++){
		b[i]=a[i];
	}
	for(int i=s.size();i>=0;i--){
		if(b[i]>=48&&b[i]<=58){
				cout<<b[i]-48;
		}
	}
	return 0;
}
