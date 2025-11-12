#include<bits/stdc++.h>
using namespace std;
int a[1000005],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[top++]=s[i]-'0';
		}
	}
	sort(a,a+top);
	//sdf
	for(int i=top-1;i>=0;i--) cout<<a[i];
	return 0;
}
