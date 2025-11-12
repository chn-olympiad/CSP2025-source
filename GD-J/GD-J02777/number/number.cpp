#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b)return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int arr[s.size()],j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[j]=s[i]-'0';
			j++;
		}
	}
	sort(arr,arr+j,cmp);
	for(int i=0;i<j;i++){
		cout<<arr[i];
	}
	return 0;
}
