#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+0;
string a[N+1];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	long long n=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>=48 && s[i]<=57){
			a[i]=s[i];
			n++;
		}
	}
	sort(a,a+s.length());
	for(int i=s.length();i>=0;i--)cout<<a[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
