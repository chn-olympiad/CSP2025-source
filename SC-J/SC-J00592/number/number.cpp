#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freeopen("number.in","r",stdin);
	freeopen("number.out","w",stdout);
	string s;
	cin>>s;
	short a[1000050];
	int ans=0,num=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';num++;
		}
	}
	sort(a,a+num,cmp);
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
	return 0;
}