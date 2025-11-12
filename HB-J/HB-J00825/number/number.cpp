#include<bits/stdc++.h> 
using namespace std;  

int main(){ 
	freopen("number.in","r",stdin); 
	freopen("number.out","t",stdout); 
	string s;   
	long long tes=0; 
	cin>>s; 
	sort(s.begin(),s.end()); 
	for(long long i=0;;i++){ 
		if(int(s[i])>=int('0')&&int(s[i])<=int('9')){ 
			tes++; 
		}else{
			break; 
		}
	} 
	for(long long i=tes-1;i>=0;i--){  
		cout<<s[i]; 
	} 
	return 0; 
}  
