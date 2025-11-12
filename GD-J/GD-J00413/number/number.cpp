#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	char c[1000010];
	cin>>c;
	int i,j,k,h[10];
	for(i=0;i<10;i++){
		h[i]=0;
	}for(i=0;i<strlen(c);i++){
		if(48<=c[i]<=57){
			k=int(c[i])-48;
			h[k]+=1;
		}
	}for(i=9;i>-1;i--){
		for(j=0;j<h[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
