#include<bits/stdc++.h>
using namespace std;
int n,m,r,z,cnt=1,a;
int main(){
	frepoen("seat.in","r"stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=n*m-1;i++){
		scanf("%d",&a);
		if(a>r)cnt++;
	}
	if(cnt%n==0)z=cnt/n;
	else z=cnt/n+1;
	if(z%2==1){
		if(cnt%n==0)printf("%d %d",z,n);
		else printf("%d %d",z,cnt%n);
	}
	else{
		if(cnt%n==0)printf("%d %d",z,n);
		else printf("%d %d",z,n-cnt%n);
	}
	return 0;
}
