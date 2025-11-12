#include<bits/stdc++.h>
using namespace std;
int k[17][17];
int n,m,w;
int a[107];
//int q(int a,int b){
//	if(a<b){
//		return b,a;
//	}
//}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int q=a[1];
	int y=n*m;
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			w=n*m-i+1;	
		}	
	}
//	printf("%d\n",w);
	int h=w;
	int ans1=0,ans2=0;
	while(h>0){
		ans1++;
		h=h-n;
	}
	h=w;
	while(h-n>0){
		h=h-n;
	}
	if(ans1%2==1){
		ans2=h;
	}
	if(ans1%2==0){
		ans2=n-h+1;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
