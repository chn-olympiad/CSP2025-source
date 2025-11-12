#include<bits/stdc++.h> 
using namespace std;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[x]++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(a[9]!=0){
			cout<<9;
			a[9]-=1;
		}else if(a[8]!=0){
			cout<<8;
			a[8]-=1;
		}else if(a[7]!=0){
			cout<<7;
			a[7]-=1;
		}else if(a[6]!=0){
			cout<<6;
			a[6]-=1;
		}else if(a[5]!=0){
			cout<<5;
			a[5]-=1;
		}else if(a[4]!=0){
			cout<<4;
			a[4]-=1;
		}else if(a[3]!=0){
			cout<<3;
			a[3]-=1;
		}else if(a[2]!=0){
			cout<<2;
			a[2]-=1;
		}else if(a[1]!=0){
			cout<<1;
			a[1]-=1;
		}else if(a[0]!=0){
			cout<<0;
			a[0]-=1;
		}
	}
	return 0;
}
