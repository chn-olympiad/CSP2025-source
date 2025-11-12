#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int arr[1000001],ans=0;
string s;
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[ans]=s[i]-'0';
			ans++;
		}
	}
	sort(arr,arr+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<arr[i];
	}
	return 0;
}

