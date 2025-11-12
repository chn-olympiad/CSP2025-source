#include<bits/stdc++.h>
using namespace std;
char a;
int b[15];
int main(){
	freopen(" number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf(" %c",&a)!=EOF){
		if(int(a-'0')<=9||int(a-'0')>=0)b[int(a-'0')]++;
	}
	bool c=0;
	for(int i=9;i>0;i--){
		while(b[i]){
			cout<<i;
			--b[i];
			c=1;
		}
	}
	if(c){
		while(b[0]){
			cout<<'0';
			--b[0];
		}
	}else{
		cout<<'0';
	}
	return 0;
}