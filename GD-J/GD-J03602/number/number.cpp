#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int arr[15] = {};
	int cnt = s.size();
	for(int i=0;i<=cnt;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			arr[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(arr[i] != 0){
			for(int j=arr[i];j>=1;j--){
				cout<<i;
			}
		}
	}
	return 0;
} 
