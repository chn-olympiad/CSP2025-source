#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,n;
	int b = 0,c = 0;
	b = a.length();
	cin>>a;
	for(int i = 0;i<b;i++){
		if(a[i] - '0' >= 0 && a[i] - '0' <= 9){
			n[c] = a[i];
			c++;
		}
	}
	sort(n.begin(),n.end());
	cout<<n;
	return 0;
	
}
