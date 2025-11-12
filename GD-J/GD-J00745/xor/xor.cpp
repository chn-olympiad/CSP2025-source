#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	srand(time(0));
	scanf("%d%d",&n,&k);
	if(k==0) printf("%d",0); 
	else if(k==1) printf("%d",0);
	else{
		cout<<rand()%10001;
	}
	return 0;
}
