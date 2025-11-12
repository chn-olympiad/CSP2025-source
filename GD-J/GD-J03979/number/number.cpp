#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	s+='#';
	for(int i=0;;i++){
		if(s[i]=='#') break;
		else{
			if(s[i]>='0' && s[i]<='9'){
				a[s[i]-'0']++;
			}
		}
	}
	bool fl=false;
	for(int i=1;i<10;i++){
		if(a[i]>0) fl=true;
	}
	if(fl){
		for(int i=9;i>=0;i--){
			if(a[i]>0){
				for(int j=1;j<=a[i];j++){
					cout<<i;
				}
			}
		}	
	}
	else cout<<0;
}
