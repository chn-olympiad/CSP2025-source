#include<bits/stdc++.h>
using namespace std;
const int N=11;
int a[N*N];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id;for(int i=1;i<=n*m;i++)if(a[i]==x)id=i;
	int ansx=1,ansy=1,fx=1;
	for(int i=2;i<=id;i++){
		ansx+=fx;
		if(ansx==n+1||ansx==0)fx=-fx,ansy++;
		if(ansx==n+1)ansx=n;
		if(ansx==0)ansx=1;
	}
	printf("%d %d\n",ansy,ansx);
	return 0;
}

