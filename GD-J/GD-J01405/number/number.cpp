#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int arr[10000];
	for(int i=0;i<1000;i++){
		cin>>arr[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]<=63&&s[i]>=53){
			arr[i]=s[i];
		}
	}
	for(int i=0;i<1000;i++){
		if(arr[i]<=arr[i+1]){
			swap(arr[i],arr[i+1]);
			cout<<arr[i];
		}
	}
	
	return 0;
} 
