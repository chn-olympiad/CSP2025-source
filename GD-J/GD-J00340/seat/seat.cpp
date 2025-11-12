#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n*m; i++){
		scanf("%d",&a[i]);
	}
	int t=n*m,g=a[1];
	sort(a+1,a+t+1,greater<int>());
	int r=0;
	for(int i=1; i<=t; i++){
		if(a[i]==g){
			r=i;
			break;
		}
	}
	int e=r%n;//hang
	int w=r/n;//lie
	if(e==0){	
		if(w&1){
			printf("%d %d",w,n);
		}else{
			printf("%d 1",w);
		}
	}else{
		w++;
		if(w&1){
			printf("%d %d",w,e);
		}else{
			printf("%d %d",w,n-e+1);
		}
	}
	return 0;
}
