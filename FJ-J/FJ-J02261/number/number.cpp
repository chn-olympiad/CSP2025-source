#include<bits/stdc++.h>
using namespace std; 
string s;
long long a[10000026],n,k,z;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(long long i=0;i<=n;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			k++;
			a[k]=s[i]-'0';
		}	
	}
	sort(a+1,a+k+1);
	for(long long i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
