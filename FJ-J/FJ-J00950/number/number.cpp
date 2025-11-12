#include<bits/stdc++.h>
using namespace std;
string s;
long long t[10]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long c=0;
	for(unsigned long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			long long tmp=s[i]-'0';
			t[tmp]++;
			c=1;
		}
	}
	if(c==0){
		cout<<0;
	}
	else{
		for(long long i=9;i>=0;i--){
			for(long long j=1;j<=t[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
/*
                                                                                                                                                      
   1   000000000  000000000                                                                                                                            
   1   0       0  0       0                                                                                                                            
   1   0       0  0       0                                                                                                                            
   1   0       0  0       0                                                                                                                            
   1   0       0  0       0                                                                                                                              
   1   0       0  0       0                                                                                                                            
   1   0       0  0       0                                                                                                                            
   1   0       0  0       0                                                                                                                            
   1   0       0  0       0                                                                                                                            
   1   000000000  000000000                                                                                                                           
                                  
*/
