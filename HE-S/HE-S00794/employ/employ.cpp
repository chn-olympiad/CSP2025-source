#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[1000],b[1000];
bool f;
int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0)f=0;
	}
	if(f){
		cout<<n-m+1;
	}
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				for(int j=i+1;j<=n;j++)b[i]--;
			}
		}
		for(int i=1;i<=n;i++){
			a[i]+=b[i];
		}
		for(int i=1;i<=n;i++){
			
		}
	}
	return 0;
}
