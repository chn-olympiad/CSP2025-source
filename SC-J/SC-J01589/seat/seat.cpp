#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int a1=a[1],ansn,ansm;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			a1=i;
			break;
		}
	}
	if(a1%n==0){
		if((a1/n)%n==1){
			ansn=n;
			ansm=a1/n;
		}
		else{
			ansn=1;
			ansm=a1/n;
		}
	}
	else{
		if((a1/n)%2==0){
			ansn=a1%n;
			ansm=a1/n+1;
		}
		else{
			ansn=n+1-a1%n;
			ansm=a1/n+1;
		}
	}
	printf("%d %d",ansm,ansn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}