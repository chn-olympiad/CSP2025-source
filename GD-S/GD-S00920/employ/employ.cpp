#include<bits/stdc++.h>
using namespace std;
int n,m;
int A(int a){
	if(a==1)return 1;
	return a*A(a-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	return cout<<A(n),0;
	/*for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		a[i]=1-a[i]+a[i-1];
	}
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	
	return 0;*/
}
