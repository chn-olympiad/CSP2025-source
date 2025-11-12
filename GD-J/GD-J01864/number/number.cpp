#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	string s;
	int arr[1000005]={},cnt=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			arr[cnt]=s[i]-'0';
			cnt++;
		}
	}
	cnt--;
	sort(arr,arr+cnt,cmp);
	for(int i=0;i<=cnt;i++){
		cout<<arr[i];
	}
	return 0;
}
