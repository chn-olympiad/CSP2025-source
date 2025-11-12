#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N*N],n,m,x,l;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1)	x=a[i];
	}
	for(int i=1;i<=n*m;i++){	sort(a+1,a+n*m+1,cmp);

		if(a[i]==x)	l=i;
	} 
	int pp=0;
	while(pp<l)	pp+=n;
	printf("%d ",pp/n);
//	cout<<pp/n<<" ";
	int ll=pp/n;
	if(ll%2==1){
		printf("%d",l-pp+n);
//		cout<<l-pp+n;
	}else{
		printf("%d",n-(l-pp+n)+1);
//		cout<<n-(l-pp+n)+1;
	}
	return 0;
}


