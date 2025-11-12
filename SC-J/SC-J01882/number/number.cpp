#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
		}
	}bool f=false;
	for(int i=9;i>=0;i--){
		if(a[i]>0&&i>0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}f=true;
		}else if(i==0&&f==true){
			for(int j=1;j<=a[0];j++){
				cout<<0;
			}
		}else if(i==0&&f==false){
			cout<<0;
		}
	}
	return 0;
}