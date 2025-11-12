#include<bits/stdc++.h>
using namespace std;
int a[10];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9') a[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
} 
