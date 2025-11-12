#include <bits/stdc++.h>
using namespace std;
long long n[13];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=a.size();
	for(int i=0;i<b;i++){
		if(a[i]<='9'&&a[i]>='0'){
			int c=a[i]-48;
			n[c]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(n[i]--){
			cout<<i;
		}
	}
	return 0;
} 
  
