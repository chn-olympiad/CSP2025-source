#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])cnt++;
	}
	int lie=(cnt+n-1)/n;
	printf("%d ",lie);
	if(cnt%n==0){
		if(lie%2==1)printf("%d",n);
		else printf("1");
	}else if(lie%2==1){
		printf("%d",cnt%n);
	}else{
		printf("%d",n-cnt%n+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

