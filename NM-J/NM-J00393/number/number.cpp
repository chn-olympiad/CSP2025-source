#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	int a[100005]={},a1=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
		s1=s1+s[i];
		a1++;
		}
	}
	for(int i=0;i<s1.length();i++){
		a[i]=s1[i]-'0';
	}	
	sort(a,a+a1,cmp);
	for(int i=0;i<a1;i++){
	cout<<a[i];
	}	
	return 0;
} 
