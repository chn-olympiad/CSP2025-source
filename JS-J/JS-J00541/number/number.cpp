#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000005],lengthx,lengthy;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	//in
	cin>>s;
	lengthx=s.length();
	
	//find numbers
	for(int i=0;i<lengthx;i++){
		if(s[i]>='0' && s[i]<='9'){
			//a.length++
			lengthy++;
			//char change to num
			a[lengthy]=s[i]-'0';
		}
	}
	
	//sort
	sort(a+1,a+lengthy+1,greater<int>());
	
	//out
	for(int i=1;i<=lengthy;i++){
		cout<<a[i];
	}
	return 0;
}
