#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+sum,cmp);
	if(a[0]==0){
		cout<<0;
		return 0;
	} 
	for(int i=0;i<sum;i++)cout<<a[i];
	return 0; 
}
