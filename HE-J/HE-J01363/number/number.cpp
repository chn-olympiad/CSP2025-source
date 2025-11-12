#include<bits/stdc++.h>
using namespace std;
int b[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	memset(b,0,sizeof b);
	while(cin>>c){
		 if(c>='0' && c<='9') b[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	return 0;
}
