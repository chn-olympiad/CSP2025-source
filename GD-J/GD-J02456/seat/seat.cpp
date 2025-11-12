#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		scanf("%d",&a[i]);
	}
	int sc=a[1];
	sort(a+1,a+nm+1,cmp);
	int id=0;
	for(int i=1;i<=nm;i++){
		if(a[i]==sc){
			id=i;
			break;
		}
	}
	int c,r;
	c=ceil(1.0*id/n);
	if(c%2!=0){
		r=id%n;
		if(r==0) r=n;
	}else{
		r=n-id%n+1;
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
