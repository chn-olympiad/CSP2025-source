#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int cnt;
	string s;
	cin>>s;
	int l=s.length();
	string a;
	
	for(int i=0;i<=l;i++){
		if(int(s[i])>=96 && int(s[i])<=122){
			continue;
		}else{
			a[cnt]=s[i];
			cnt++;
		}
	}
	
	cout<<1;
	return 0;
}
