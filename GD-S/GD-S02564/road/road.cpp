#include<bits/stdc++.h>
using namespace std;
long long n,m,k,p;
struct node{
	int u,v,mo;
}a[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].mo);
		p+=a[i].mo;
		n--;
		if(n==0)break;
	}
	cout<<p;
	return 0;
}
