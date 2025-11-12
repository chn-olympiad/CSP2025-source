#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int f=s.size();
	for(int i=0;i<f;i++){
		if(s[i]<'0'||s[i]>'9'){
			s.erase(i,1);
		}
	}
	f=s.size();
	for(int i=0;i<f;i++){
		for(int j=i+1;j<f;j++){
			if(s[i]<s[j]){
				char x=s[i];
				s[i]=s[j];
				s[j]=x;
			}
		}
	}
	int k=0;
	for(int i=0;i<f;i++){
		int flag=1;
		for(int j=i+1;j<f;j++){
			flag*=10;
		}
		int l=(s[i]-'0')*flag;
		k+=l;
	}
	cout<<k;
	return 0;
}
