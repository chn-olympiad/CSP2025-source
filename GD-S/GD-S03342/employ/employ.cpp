#include<bits/stdc++.h>
using namespace std;
long long n,m,c[501];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld,%lld",n,m);
	string s;
	long long zero=0;
	
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			zero++; 
		}
	}
	if(zero==n){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
