#include<bits/stdc++.h>
using namespace std;
long long b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	while(cin>>a){
		if(a>='0'&&a<='9'){
			b[a-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	return 0;
}
