#include<bits/stdc++.h>
using namespace std;
char s;
long long a[10000],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if('0'<=s&&s<='9')a[s-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			printf("%ld",i);
			a[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
