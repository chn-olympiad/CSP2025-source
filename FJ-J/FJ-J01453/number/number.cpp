#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;char a,b[100005],c;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		a=s[i];
		if(a>='0'&&a<='9'){
			b[c]=s[i];
			c++;
		}
	}
	for(int i=0;i<c;i++){
		for(int j=i+1;j<c;j++){
			if(b[i]<b[j]) swap(b[i],b[j]);
		}
	}
	for(int i=0;i<c;i++){
	cout<<b[i];	
	}
	return 0;
} 
