#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000005];
	cin>>s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if(s[j]<s[j+1]){
				int t=0;
				t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
		cout<<s[i];
		}
	}
	return 0;
} 
