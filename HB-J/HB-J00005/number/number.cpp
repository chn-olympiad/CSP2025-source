#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int js;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[js]=s[i]-'0';
			js++;
		}
	}
	sort(a,a+js);
	for(int i=js-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;	
}
