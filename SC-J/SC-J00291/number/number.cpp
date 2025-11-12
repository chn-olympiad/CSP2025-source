#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i]=-1;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[i]=s[i];
		}
	}
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			if(a[j]>=a[i]){
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(a[i]!=-1){
			char b;
			b=a[i];
			cout<<b;
		}
	}
	return 0;
} 