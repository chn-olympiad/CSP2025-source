#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b,z={0};
	int mx=0;
	int ans=0;
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){ 
			b[ans]=s[i];
			ans++;
		}
	}	
	for(int i=1;i>0;i++){
		for(int i=1;i<ans;i++){
		if(b[i]<b[i+1])swap(b[i],b[i+1]);
	}
	if(z==b){
		z=b;
	}else{
		break;
	}
	
	}
	
	for(int i=0;i<ans;i++){
		cout<<char(b[i]);
	}
	return 0;
} 
