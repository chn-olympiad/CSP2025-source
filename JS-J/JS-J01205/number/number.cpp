#include<bits/stdc++.h>
using namespace std;
const int MAX=100000;
char a;
int b[10],i=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		i++;
		if(a<='9'&&a>='0'){
			b[a-'0']++;
		}
	}
	for(int j=9;j>=0;j--){
		for(int k=0;k<b[j];k++)
			cout<<j;
			}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
