//number
#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin>>c){
		if(c>='0' && c<='9') a[(c-'0')]++;
	}
	for(int i=9; i>=0; i--){
		if(a[i]){
			for(int j=1; j<=a[i]; j++) cout<<i;
		}
	}
	return 0;
} 
