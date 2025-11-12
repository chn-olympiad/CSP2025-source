#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[105],n,m,s,bj,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	if(n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	s=a[0];
	int k=n*m;
	sort(a,a+k,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==s){
			bj=i+1;
			break;
		}
	}
	if(bj%n==0)c=bj/n;
	else c=bj/n+1;
	if(c&1)r=bj-n*(c-1);
	else r=n-(bj-n*(c-1))+1;
	printf("%d %d",c,r);
	return 0;
} 
