#include<bits/stdc++.h>
using namespace std;
int a[1000003];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	string s;
	cin>>s;
	int sum=0,m=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
			if(s[i]=='0'){
				m++;
			}else{
				sum++;
			}
		}
	}
	int n=s.size();
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[i]!=0){
			cout<<a[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<"0";
	}
	return 0;
}
