#include<bits/stdc++.h>
using namespace std;
int n,m,dn,dm;
int a[105];
bool pd(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int r=a[1];
	sort(a+1,a+1+n*m,pd);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			dm=i/n+(i%n==0?0:1);
			if(dm%2==0){
				dn=n-(i%n)+1;
				if(dn>n)dn=1;
			}
			else{
				dn=i%n;
				if(dn<=0)dn=n;
			}
			break;
		}
	}
	printf("%d %d",dm,dn);
	return 0;
}

