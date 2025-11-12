#include<bits/stdc++.h>
using namespace std;
int a[10];
string s;
bool f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>0;i--){
		if(a[i]>0){
			f=1;
		}
		while(a[i]--){
			cout<<i;
		}
	}
	if(f){
		while(a[0]>0){
			cout<<0;
			a[0]--;
		}
	}else{
		cout<<0; 
	}
	return 0;
}
