#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string arr;
int s[1000005];
int j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>arr;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>='0'&&arr[i]<='9'){
			s[j]=arr[i]-'0';
			j++;
		}
	}
	sort(s,s+j);
	for(int i=j-1;i>=0;i--){
		cout<<s[i];
	}
	return 0;
}