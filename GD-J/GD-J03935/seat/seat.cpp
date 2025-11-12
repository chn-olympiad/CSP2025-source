#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,a[105],b[15][15],R,l,r,ans1,ans2;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",a+i);
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=R)r=mid-1;
		else l=mid+1;
	}
	while(l-n>=0)l-=n,ans1++;
	if(l==0){
		printf("%d %d",ans1,n);
	}else{
		ans1++;
		if(ans1&1){
			printf("%d %d",ans1,l);
		}else{
			printf("%d %d",ans1,n-l+1);
		}
	} 
	return 0;
} 

