#include<iostream>
#include<algorithm>
using namespace std; 
const int N=105;
int n,m;
int a[N],cnt[N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	int id=1;
	for(int i=a[1]+1;i<=100;i++) id+=cnt[i];
	int c=(id-1)/n+1,r=id-(c-1)*n;
	if(c%2==0) r=n-r+1;
	printf("%d %d",c,r); 
	return 0;
}
