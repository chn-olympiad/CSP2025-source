#include<bits/stdc++.h>
using namespace std;
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n=0;
	string s;
	cin>>s;
	long long x[s.size()];
	for(long long i=0;i<s.size();i+=1){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			x[n]=s[i]-'0';
			n+=1;
		}
	}
	sort(x,x+n,c);
	for(long long i=0;i<n;i+=1){
		cout<<x[i]; 
	}
	return 0; 
} 
