#include<bits/stdc++.h>
using namespace std;
const int N=1000;
struct student{int val,id;}a[N];
int n,m;
bool cmp(student x,student y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;++i)
		if(i%2)
			for(int j=1;j<=n;++j){
				int now=(i-1)*n+j;
				if(a[now].id==1){
					printf("%d %d",i,j);
					return 0;
				}
			}
		else for(int j=n;j>=1;--j){
			int now=(i-1)*n+(n-j+1);
			if(a[now].id==1){
				printf("%d %d",i,j);
				return 0;
			}
		}
	return 0;
}

