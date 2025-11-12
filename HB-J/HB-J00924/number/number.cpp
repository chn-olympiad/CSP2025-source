#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10]={},l;
	string s;
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9)a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			for(int j=0;j<a[i];j++)cout<<i;
		}
	}



	return 0;
}
