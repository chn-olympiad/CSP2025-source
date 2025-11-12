#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	string s1="";
	int max=INT_MIN;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			s1+=s[i];	
		}
	}
//	int arr[s1.size()];
	
	for(int i=0;i<s1.size();i++){
		arr[i]=s1[i]-'0';	
	}
	sort(arr,arr+s1.size());
	for(int i=s1.size()-1;i>=0;i--){
		cout<<arr[i];	
	}
	return 0;
}
