#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=1,x,num,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for (int i=2;i<=n*m;i++){
		scanf("%lld",&num);
		if (num>x){
			cnt++;
		}
	}
	if (cnt%n==0){
		printf("%lld ",cnt/n);
		l=cnt/n;
	}else{
		printf("%lld ",cnt/n+1);
		l=cnt/n+1;
	}
	if (l%2==1){
		if (cnt%n==0){
			printf("%lld",n);
		}else{
			printf("%lld",cnt%n);
		}
	}else{
		if (cnt%n==0){
			printf("%lld",1);
		}else{
			printf("%lld",n-cnt%n+1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
