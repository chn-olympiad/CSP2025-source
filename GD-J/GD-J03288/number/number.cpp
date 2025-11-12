#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	//freopen("number.cpp","r",stdin);
	//freopen("number.cpp","w",stdout);
	string s;
	cin>>s;
	int q=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			q++;
		}
	}
	sort(a,a+q+1);
	for(int i=q;i>0;i--){
		cout<<a[i]; 
	} 
} 
