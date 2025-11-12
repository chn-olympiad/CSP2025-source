#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k;
bool cmp(int a,int b){
	return a>b;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int p=1;
	while(a[p]!=k)p++;
	int ins=p%n,huk=p/n+1;
	if(huk%2==1)printf("%d %d",huk,ins);
	else printf("%d %d",huk,n-ins+1);
	fclose(stdin); fclose(stdout);
	return 0;
}