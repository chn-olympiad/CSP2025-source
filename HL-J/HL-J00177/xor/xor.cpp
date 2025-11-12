#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%d",n);
	
}
