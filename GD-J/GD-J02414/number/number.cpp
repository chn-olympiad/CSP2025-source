#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	string word;
	cin>>word;
	for(int i=0;i<word.size();i++){
		if(word[i]>='0'&&word[i]<='9'){
			arr[word[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(arr[i]>0){
			arr[i]--;
			cout<<i;
		}
	}
	return 0;
} 
