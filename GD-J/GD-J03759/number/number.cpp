#include<bits/stdc++.h> 
using namespace std;

int a[1000005],m;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[m]=s[i]-'0'; 
			m++;
		}
	}
	
	sort(a,a+m,cmp);
	
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	
	return 0;
}
