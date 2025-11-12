#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
int a[1000001],l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=s.size()-1;
	for(int i=0;i<=t;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--){
		cout<<a[i];
	}
	
	return 0;
} 
/*
1=拿下！

注意freopen注释 
1.100
*/