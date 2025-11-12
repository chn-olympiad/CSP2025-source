#include<bits/stdc++.h>
using namespace std;
int n,t,b[100];
char a[2000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a[++t]);
	for(int i=1;i<=t;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]!=0){
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
