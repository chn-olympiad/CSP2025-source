#include<bits/stdc++.h>
using namespace std;
long long a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char n;
	bool p=0;
	n=getchar();
	while(n!=10){
		if(n>=48&&n<=57){
			a[n-48]+=1;
		}
		n=getchar();
	}
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			if(i!=0)p=1;
			if(p==1)printf("%lld",i);
			else{
				cout<<0;
				break;
			}
		}
		
	}
	return 0;
}
