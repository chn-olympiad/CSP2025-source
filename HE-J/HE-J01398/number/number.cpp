#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long a=s.length(),t=0,n;
	string f;
	for(long long i=0;i<a;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			f[t]=s[i];
			t++;
		}
	}
	long long r=t;
	while(r!=0){
	for(long long i=0;i<=r;i++){
		if(f[i]<f[i+1]){
			swap(f[i],f[i+1]);
		}
	}
	r--;
	}
	for(long long i=0;i<t;i++){
		cout<<f[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
