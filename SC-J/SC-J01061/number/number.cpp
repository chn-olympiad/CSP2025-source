#include <bits/stdc++.h>
using namespace std;
long long b[10];
string a;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i] != 0;i++){
		int c=a[i];
		if(c>47 && c<59){
			b[c-48]++; 
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]>0){
			printf("%d",i);
			b[i]--;
		}
	}
	return 0;
}