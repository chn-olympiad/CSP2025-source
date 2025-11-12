#include<bits/stdc++.h>
using namespace std;
int arr[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[int(s[i]-48)]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(arr[i]>0){
			cout<<i;
			arr[i]--;
		}
	}
	
	return 0;
} 
