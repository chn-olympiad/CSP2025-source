#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={0,0,0,0,0,0,0,0,0};
	int l=s.size();
	for(int i=0;i<=l;i++){
		if(s[i]-48<=9 && s[i]-48>=0){
			a[s[i]-48]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
}
