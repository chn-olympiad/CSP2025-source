#include<bits/stdc++.h>
using namespace std;
bool com(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[s.size()+1];
	long long j=0;
	for(long long i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[j]=s[i]-'0';
			j++;			
		}
	}
	sort(a,a+j,com);
	for(long long i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
} 
