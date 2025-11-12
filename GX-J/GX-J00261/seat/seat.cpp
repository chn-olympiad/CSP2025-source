#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int n,m;
int t,p=1,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&t);
	for(int i=2;i<=n*m;i++){
		int u;
		scanf("%d",&u);
		if(u>t)	p++;
	}
	for(int i=1;i<=m;i++)
		if((i*n+1)>p){
			q=i;
			break;
		}
	//cout<<q<<' '<<p<<endl;
	int v=p%n;
	if(p%n==0)	v=n;
	if(q%2==1)	printf("%d %d",q,v);
	else    printf("%d %d",q,(n-v+1));
	return 0;
}
