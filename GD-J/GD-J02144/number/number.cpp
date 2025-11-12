#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000000];
long long num = 0;
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	cin>>a;
	long long  na = a.length();
	for(int i = 0;i<na;i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[num++] = a[i]-'0';
		}
	}
	sort(b+0,b+num);
	for(int i = num-1;i>=0;i--){
		cout<<b[i]; 
	}
	return 0;
} 
