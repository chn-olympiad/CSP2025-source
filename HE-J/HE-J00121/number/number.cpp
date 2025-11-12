#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	int n=a.size();
	int c[10];
	for (int i=0; i<10; i++){
		c[i]=0;
	}
	for(int i=0; i<n; i++){
		if (a[i]>='0' && a[i]<='9'){
			c[int(a[i]-'0')]++;
		}
		
	}
	
	for (int i=9; i>=0; i--){
		for (int k=1; k<=c[i]; k++){
			cout<<i;
		}
	}
	
	return 0;
}
