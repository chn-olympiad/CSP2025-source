#include<bits/stdc++.h>
using namespace std;
int a[1000500];	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int index=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[index++]=s[i]-'0';
		}
	}
	sort(a,a+index);
	bool t=false;
	for(int i=index-1;i>=0;i--){
		if(a[i]!=0){
			t=true;
		}
		if(t){
			cout<<a[i];
		}
	}
	return 0;
}