#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x>=y){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int shu[n*m+10];
	for(int i=1;i<=n*m;i+=1){
		scanf("%d",&shu[i]);
	}
	int rf=shu[1],rd;
	sort(shu+1,shu+1+n*m,cmp);
	for(int i=1;i<=n*m;i+=1){
		if(shu[i]==rf){
			rd=i;
			break;
		}
	}
	if(rd<=n){
		printf("%d %d",1,rd);
	}else if(rd%n!=0){
		if((rd/n+1)%2==0){
			printf("%d %d",rd/n+1,n-rd%n+1);
		}else{
			printf("%d %d",rd/n+1,rd%n);
		}
	}else{
		printf("%d %d",rd/n,n);
	}
	return 0;
}
