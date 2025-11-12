#include<bits/stdc++.h>
using namespace std;
int arr[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<(int)str.size();i++){
		if(str[i]<='9'&&str[i]>='0')arr[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<arr[i];j++)cout<<i;
	}
	return 0;
}
