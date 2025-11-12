#include<bits/stdc++.h> 
using namespace std;
int a[1000000]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int po=0;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9'&&str[i]>='0'){
			a[po]=str[i]-'0';
			po++;
		}
	}
	sort(a,a+str.size(),cmp);
	for(int i=0;i<po;i++){
		cout<<a[i];
	}
	return 0;
}