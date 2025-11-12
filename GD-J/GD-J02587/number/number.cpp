#include<bits/stdc++.h> 
using namespace std;
int a[101];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c=getchar();
	while(c!='\n'){
		if(c>='0'&&c<='9'){
			int t=c-'0';
			a[t]++;
		}
		c=getchar();
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
}
