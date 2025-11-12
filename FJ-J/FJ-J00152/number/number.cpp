#include <bits/stdc++.h>
using namespace std;
long long sum[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	char c=getchar();
	while((c>='0'&&c<='9')||(c>='a'&&c<='z')){
		if(c>='0'&&c<='9'){
			sum[c-'0']++;
		}
		c=getchar();	
	} 
	for(int i=9;i>=0;i--){
		c=i+'0';
		while(sum[i]){
			printf("%.c",c);
			sum[i]--;
		}
	}
	return 0;
}	 
