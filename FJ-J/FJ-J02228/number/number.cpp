#include<bits/stdc++.h>
using namespace std;
string s;
int a[1145140],cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=1;i<=l;i++){
		if(s[i-1]>=48&&s[i-1]<=57){
			a[cnt]=s[i-1]-48;
			cnt++;
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
