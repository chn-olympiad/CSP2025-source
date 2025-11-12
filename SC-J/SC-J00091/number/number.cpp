#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int n=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+s.size()-1,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
//2025 CSP-J RP++
//I AK CSP