#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=0,s[1000001];
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			t++;
			s[t]=int(a[i]);
		}
	}
	sort(s+1,s+t+1);
	for(int i=1;i<=t;i++){
		cout<<s[i];
	}
	return 0;
}

