#include<bits/stdc++.h> 
using namespace std;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int q[10][2];
	for(int i=0;i<10;i++)
		q[i][0]=i;
	
	cin>>s;
	int j=0;
	
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q[s[i]-'0'][1]++;
			
		} 
	}
	
	
	
			
		
	


	
	
	for(int i=9;i>=0;i--){
		
		for(int k=0;k<q[i][1];k++){
			cout<<q[i][0];
		}
	}
	
	
	return 0;
}