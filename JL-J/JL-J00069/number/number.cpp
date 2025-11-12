#include<bits/stdc++.h>
using namespace std;
int a[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	while(cin>>s){
		if(s>='0'&&s<='9'){
			int x=s-'0';
			a[x]+=1;
		}
	}
	for(int k=9;k>=0;k--){
		for(int j=0;j<a[k];j++){
			printf("%d",k);
		}
	}
	return 0;
}
