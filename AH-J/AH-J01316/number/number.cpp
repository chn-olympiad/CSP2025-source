#include <bits/stdc++.h>

using namespace std;
int a[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),t=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+1+t);
	if(a[t]==0) cout<<0;
	else{
		for(int i=t;i>=1;i--){
			cout<<a[i];
		}
	}
	
	return 0;
}
