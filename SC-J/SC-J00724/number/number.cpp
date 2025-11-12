#include <bits/stdc++.h>
using namespace std;
string s;
int a[1005]={0};
int main(){
	getline(cin,s);
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>=48&&s[i]<=58){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>-1;i--){
		if(a[i]!=0){
			int b=a[i];
			for(int j=1;j<=b;j++){
				cout<<i;
			}
		}
	}
	return 0;
}