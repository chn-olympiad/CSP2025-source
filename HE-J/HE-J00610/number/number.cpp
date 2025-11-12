#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r"stdin),;
	freopen("number.out","w",stdout);
	string s,num,ma;
	int ans,m=1;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num+=s[i];	
		}
	}
		
	for(int i=0;i<num.size();i++){
		
	if(num[i]<num[i+1]){
		ma+=num[i+1];
		
	}
      
	   
	
		
	}
	 cout<<ma;
	return 0;
	
}
