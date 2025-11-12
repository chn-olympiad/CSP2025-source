#include<bits/stdc++.h>
using namespace std;
int i=1,j;
char aa[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(aa[i]=getchar()){
		if(aa[i]==10)
			break;
		else
			i++;
	}
	sort(aa+1,aa+i+1);
	for(int b=i;b>=1;b--){
		if(48<=aa[b]&&aa[b]<=57)
			cout<<aa[b];
	}
	return 0;
}

