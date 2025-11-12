#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int q=n*m;
	for(int i=1;i<=q;++i){
		scanf("%d",&b[i]);
	}
	int r=b[1];
	sort(b+1,b+q+1);
	int cnt=0;
	for(int i=1;i<=q;++i){
		if(b[i]==r){
			cnt=q-i+1;
			break;
		}
	}
	int x=cnt/n+1;
	int y=cnt-cnt/n*n;
	if(x%2==1){
		printf("%d %d",x,y);
	}
	else if(x%2==0){
		printf("%d %d",x,n-y+1);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
