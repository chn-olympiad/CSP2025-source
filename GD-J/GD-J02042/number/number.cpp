#include<bits/stdc++.h>
using namespace std;
char s;
int n[1000007],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0' and s<='9'){
			n[k++]=s-'0';
		}
	}
	sort(n,n+k); 
	for(int i=k-1;i>=0;i--)cout<<n[i];
	return 0;
} 
