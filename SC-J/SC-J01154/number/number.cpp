#include<bits/stdc++.h>
using namespace std;
char c[1000005];
int k,a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c[++k]);
	for(int i=1;i<=k;i++){
		if('0'<=c[i]<'9'){
			a[(c[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
} 