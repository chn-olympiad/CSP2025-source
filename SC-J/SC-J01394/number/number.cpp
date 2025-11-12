#include<bits/stdc++.h>
using namespace std;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin>>c)if(isdigit(c))++num[c-'0'];
	for(int i=9;i>=0;--i){
		for(int j=1;j<=num[i];++j)printf("%d",i);
	}
	return 0;
} 