#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int now=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	for(int i=0;i<b.length();i++){
		if(b[i]<='9'&&b[i]>='0'){
			a[++now]=b[i]-'0';
		}
	}
	sort(a+1,a+now+1);
	for(int i=now;i>=1;i--){
		cout<<a[i];
	}
	
	
	return 0;
} 
