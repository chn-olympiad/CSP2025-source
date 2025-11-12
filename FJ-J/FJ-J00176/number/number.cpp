#include<bits/stdc++.h>
using namespace std;
int a[15];
long long sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int y=1;
	cin >>s;
	int len1=s.length();
	for(int i=0;i<len1;i++){
		if(s[i]>=48 and s[i]<=57){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0 and i!=0){
			y=0;
		}if(i==0 and y==1){
			break;
		} 
		for(int j=1;j<=a[i];j++){
		cout<<i; 
		}
	}
	if(y==1){
		cout<<0;
	}
	return 0;
}
