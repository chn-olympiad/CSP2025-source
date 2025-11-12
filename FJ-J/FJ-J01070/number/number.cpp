#include<bits/stdc++.h>
using namespace std;


int t[1000005],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9') t[s[i]-'0']++,sum++;
	}
	
	
	if(sum==t[0]){
		cout<<0;
	}else{
		for(int i=9;i>=0;i--){
			for(int j=0;j<t[i];j++){
				cout<<i;
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
} 
