#include<bits/stdc++.h>
using namespace std;
int n,m,a1,ai,c=0,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a1);
	for(int i=1;i<n*m;i++){
		scanf("%d",&ai);
		if(ai>a1) c++;
	}
	if(c==0){
		printf("1 1");
		return 0;
	}
	int x=c/n+1,y=c%n;
	printf("%d ",x);
	if(x%2==0){
		ans=n-y;
		printf("%d",ans);
	}else{
		ans=y+1;
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
