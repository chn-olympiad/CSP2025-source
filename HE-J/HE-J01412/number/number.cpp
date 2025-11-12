#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int maxx=-1,t=1;
	cin>>s;
	for(int i = 0;i <= s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+t);
	for(int i = t-1;i >= 1;i--){
		cout<<a[i];
	}
	return 0;
}
