#include<bits/stdc++.h>
using namespace std;
int n,m=1,a[1010000];
char l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>l){
		if(l>='0'&&l<='9'){
			a[++n]=l-'0'; 
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
