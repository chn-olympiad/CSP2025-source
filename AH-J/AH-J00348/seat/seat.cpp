#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+m*n+1,cmp);
	int sx=1,sy=1;
	bool f=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			printf("%d %d",sy,sx);
			break;
		}
		if(f) sy++;
		else sy--;
		if(f&&sy==n+1) sy--,sx++,f=!f;
		if(!f&&sy==0) sy++,sx++,f=!f;
	}
	return 0;
}
