#include<bits/stdc++.h>
using namespace std;
int a[500010],k,n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	scanf("%d%d",&n,&k);
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;
	}
	if(flag==0)cout<<1;
	else cout<<0;
	return 0;
} 
