#include<bits/stdc++.h> 
using namespace std;
int arr[5000001]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	int pos=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[pos]=s[i]-'0';
			pos++;
		}
	}
	sort(arr,arr+pos,greater<int>());
	for(int i=0;i<pos;i++)cout<<arr[i];
	return 0;
}
