#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int p;
	scanf("%d",&p);
	a[1]=p;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m+1,cmp);
	int h=1,l=1,sum=1,f=1;
	while(l<=m&&sum<=n*m){
		if(a[sum]==p)break;
		h+=f;
		if(h==n+1){
			h=n;
			l++;
			f=-1;
		}
		if(h==0&&l%2==0){
			h=1;
			l++;
		}
		sum++;
	}
	printf("%d %d",l,h);
	return 0;
}
