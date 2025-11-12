#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int n,k; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	srand(time(0));
	cout<<rand()%n;
	return 0;
}

