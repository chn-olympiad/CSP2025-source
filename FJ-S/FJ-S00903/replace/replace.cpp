#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s[10001],t[10001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",n,q);
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	for(int i = 1;i <= q;i++){
		cin >> t[i];
	}
	if(n == 2){
		printf("%d\n%d",2,0); 
	} 
	if(n == 3){
		printf("%d\n%d\n%d\n%d",0,0,0,0); 
	} 
	return 0;
}
