#include<bits/stdc++.h> 

using namespace std;

long long tong[10];

int main(){
	
	freopen("number.in","r",stdin);
	
	freopen("number.out","w",stdout);
	
	string a;
	
	cin>>a;
	
	for(long long i=0;i<a.length();i++){
		
		if(a[i]<='9'&&a[i]>='0'){
			
			tong[a[i]-'0']++;
		}
	}
	
	for(long long i=9;i>=0;i--){
		
		while(tong[i]!=0){
			
			cout<<i; 
			
			tong[i]--;
		}
	}
	
	fclose(stdin);
	
	fclose(stdout);
	
	return 0;
}
