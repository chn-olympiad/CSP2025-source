#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	if(a>b){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	string s;
	cin>>s;
	int arr[2000]={};
	for(int i=0;i<s.length();i++){
		if(s[i]<='9' and s[i]>='0'){
			arr[i]=s[i]-48;
		}else{
			arr[i]=10;
		}
	}
	sort(arr,arr+s.length(),cmp);
	for(int i=0;i<s.length();i++){
		if( arr[i]==10){
			
		}else{
			cout<<arr[i];
		}
		
	}
	return 0;
}
