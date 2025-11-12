#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010],k=0;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			k++;
			a[k]=int(s[i]-'0');
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
