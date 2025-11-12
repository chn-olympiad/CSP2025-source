#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		 }
	}
	while(a[9]!=0){
		cout<<"9";
		a[9]--;
	}
	while(a[8]!=0){
		cout<<"8";
		a[8]--;
	}
	while(a[7]!=0){
		cout<<"7";
		a[7]--;
	}
	while(a[6]!=0){
		cout<<"6";
		a[6]--;
	}
	while(a[5]!=0){
		cout<<"5";
		a[5]--;
	}
	while(a[4]!=0){
		cout<<"4";
		a[4]--;
	}
	while(a[3]!=0){
		cout<<"3";
		a[3]--;
	}
	while(a[2]!=0){
		cout<<"2";
		a[2]--;
	}
	while(a[1]!=0){
		cout<<"1";
		a[1]--;
	}
	while(a[0]!=0){
		cout<<"0";
		a[0]--;
	}
	return 0;
}
