#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int MIN=1e8+10;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int cnt=1;
	if(s.size()==1){
		cout << s << '\n';
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='1'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='2'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='3'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='4'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='5'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='6'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='7'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='8'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==9){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==8){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==7){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==6){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==5){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==4){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==3){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==2){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==1){
			cout << a[i];
			a[i]=MIN;
		}
	}
	for(int i=1;i<cnt;i++){
		if(a[i]==0){
			cout << a[i];
			a[i]=MIN;
		}
	}
	cout << '\n';
	return 0;
} 
