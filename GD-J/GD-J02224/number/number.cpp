#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	char a[s.size()];
	bool f=false;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[cnt++]=s[i];
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<a[i]
	}
	return 0;
} 
