#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	long long s=5,seq=92100;
	scanf("%d%d",&s,&seq);
	for(int i=1;i<=s;i++){
	    s+=5;
	}
	for(int i=1;i<=seq;i++){
		seq+=92100;
	}
		printf("%d%d",&s,&seq); 
	
	return 0;
} 
