#include<bits/stdc++.h>
using namespace std;
int arr[int(1e6+10)],idx=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[++idx]=int(s[i]-'0');
		}
	}
	sort(arr+1,arr+1+idx,cmp);
	for(int i=1;i<=idx;i++) cout<<arr[i];
	return 0;
}
