#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

string s;
int ans[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			if(s[i]=='0') ans[0]++;	
			if(s[i]=='1') ans[1]++;
			if(s[i]=='2') ans[2]++;
			if(s[i]=='3') ans[3]++;
			if(s[i]=='4') ans[4]++;
			if(s[i]=='5') ans[5]++;
			if(s[i]=='6') ans[6]++;
			if(s[i]=='7') ans[7]++;
			if(s[i]=='8') ans[8]++;
			if(s[i]=='9') ans[9]++;
		}
	}	
	for(int i=9;i>=0;i--){
		for(int j=0;j<ans[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
