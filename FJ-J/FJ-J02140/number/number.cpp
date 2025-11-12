#include<bits/stdc++.h>
using namespace std;
char a;
long long c,d,b[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if(a>='0'&&a<='9'){
			d=a-48;
			b[d]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=b[i];j>=1;j--){
			cout<<i;
		}
	}
	


	return 0;
}

