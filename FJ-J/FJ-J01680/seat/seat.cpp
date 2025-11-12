//seat.cpp
#include<bits/stdc++.h>
using namespace std;

bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105]={0};
	scanf("%d%d",&n,&m);
	int sum=n*m;
	for(int i=1;i<=sum;i++) scanf("%d",&a[i]);
	int v=a[1],x=0,y=0,cnt=0;
	sort(a+1,a+sum+1,cmp);
	bool yrn=true;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(a[cnt]==v){
				y=i;
				if(yrn) x=j;
				else x=n-j+1;
				break;
			}
		}
		if(yrn) yrn=false;
		else yrn=true;
	}
	printf("%d %d",y,x);
	return 0;
}
