#include<bits/stdc++.h>
using namespace std;
int a[105],st;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1) st=a[i];
	}
	sort(a+1,a+n*m+1);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==st) break;
		cnt++;
	}
	cnt=n*m-cnt;
	for(int col=1;col<=n;col++){
		for(int row=1;row<=m;row++){
			if(cnt==1){
				printf("%d %d\n",col,row);
			}
			cnt--;
		}
		col++;
		for(int row=m;row>=1;row--){
			if(cnt==1) printf("%d %d\n",col,row);
			cnt--;
		}
	}
	
	return 0;
}

