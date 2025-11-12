#include<bits/stdc++.h>
using namespace std;
int n,k,a,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		t^=a;
	}
	srand(t*n*k);
	printf("%d",rand());
	return 0;
}
