#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
int a[101];
int R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d",&R);
	int t=n*m;
	a[R]=1;
	for(int i=2;i<=t;++i){
		int tt;
		scanf("%d",&tt);
		a[tt]=1;
	}
	int num=0;
	for(int i=100;i>=R;--i){
		if(a[i]==1) num++;
	}
	int c=num/n;
	int r=num%n;
	if(num%n!=0) c+=1;
	printf("%d",c);
	cout<<" ";
	if(c%2==0){
		if(r==0) printf("%d",1);
		else printf("%d",n-r+1);
	}
	else{
		if(r==0) printf("%d",n);
		else printf("%d",r);
	}
	return 0;
}

