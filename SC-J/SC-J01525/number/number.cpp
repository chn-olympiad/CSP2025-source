#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long ii=0;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		int aa=s[i]-'0';
		
		if(0<=aa&&aa<=9)a[ii++]=aa;
	}
	sort(a,a+ii);
	long long ans=0;
	for(long long i=ii-1;i>=0;i--){
		cout<<a[i];
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

