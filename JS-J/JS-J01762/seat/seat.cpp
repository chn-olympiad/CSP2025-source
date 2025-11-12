#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[125];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i*n+j]);
		}
	}
	int tp=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int c=1,r=0;
	for(int i=1;i<=n*m;i++){
		if(r<n&&(c&1)){
			r++;
		}else if(r==n&&(c&1)){
			c++;
		}else if((!(c&1))&&r>1){
			r--;
		}else if(r==1&&(!(c&1))){
			c++;
		}
		if(a[i]==tp){
			printf("%d %d\n",c,r);
			break;
		}
	}
	return 0;
}