#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int s=n*m,la=0,n2,m2;
	int a[s];
	for(int i=0;i<s;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[0])la++;
	}
	n2=la/n+1;
	if(n2%2==0){
		m2=n-(la%n);
	}
	else m2=(la%n)+1;
	printf("%d %d",n2,m2);
	return 0;
}
