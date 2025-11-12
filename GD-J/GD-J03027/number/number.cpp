#include<bits/stdc++.h>
using namespace std;
int a[1100000],cnt;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>=48&&s[i]<=57){
			cnt++;
			a[cnt]=s[i]-48;
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	
	return 0;
}
