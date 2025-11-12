#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[i+1]=s[i]-'0';
			ans++;
		}
	}
	sort(a+1,a+s.size()+1);
	int n=0;
	for(int i=s.size();i>ans;i--){
		n=n*10+a[i];
	}
	cout<<n;
	return 0;
}
