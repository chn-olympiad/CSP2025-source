#include<bits/stdc++.h>
using namespace std;
bool cmp(short a,short b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int ans=0,sum=0,k=0;
	short a[1000000]={};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[ans++]=s[i]-48;	
		}
	}
	sort(a,a+ans,cmp);
	while(sum==0){
		sum+=a[k++];
		if(k==ans&&sum==0){
			cout<<0;
			return 0;
		}
	}
	for(int i=0;i<ans;i++)cout<<char(a[i]+48);
	return 0;
}
