#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("saet.out","w",stdout);
	int n=0,m=0,xr=0,x=0,y=0;
	scanf("%d%d",&n,&m);
	int b[105]={};
//	,c[105]={};
	//int a[15][15]={};
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){
		scanf("%d",&b[i]);
		if(i==1){
			xr=b[i];
		}
//		c[b[i]]++;
	}
	sort(b+1,b+cnt+1,cmp);
	int q=1;
	bool flag=false;
//	for(int i=1;i<=cnt;i++){
//		cout<<b[i]<<' ';
//	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
	//			cout<<b[q]<<' ';
				if(b[q]==xr){
					x=i;y=j;
	//				cout<<1<<'\n';
					flag=true;
					break;
				}
				q++;
			}
		}if(i%2==0){
			for(int j=m;j>=1;j--){
	//			cout<<b[q]<<' ';
				if(b[q]==xr){
					x=i;y=j;
	//				cout<<1<<'\n';
					flag=true;
					break;
				}
				q++;
			}
		}
			
//		cout<<'\n';
		if(flag==true){
//			cout<<2;
			break;
		}
	}
	printf("%d %d",x,y);
	return 0;
}
