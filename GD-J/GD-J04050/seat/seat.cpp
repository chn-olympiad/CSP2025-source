#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int mk;
	int nu;
}a[105];
bool cmp(stu frs,stu scd){
	return frs.mk>=scd.mk;
}
int n,m;
int ii=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].mk);
		a[i].nu=i;
	}
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;;i+=2){
		for(int j=1;j<=m;j++){
			ii++;
			if(a[ii].nu==1){
				printf("%d %d",i,j);
				return 0;
			}
		}
		for(int j=m;j>=1;j--){
			ii++;
			if(a[ii].nu==1){
				printf("%d %d",i+1,j);
				return 0;
			}
		}
	}
	return 0;
}
