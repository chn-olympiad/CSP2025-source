#include<bits/stdc++.h>
using namespace std;
int n,m;
int rone;
int all[1001];
int cixu=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&all[i]);
	}
	rone=all[1];
	sort(all+1,all+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(all[i]==rone){
			cixu=n*m-i+1;
			break;
		}
	}
	int p=cixu/(n*2);
	int q=cixu%(n*2);
	int lie=p*2+1;
	//printf("p=%d q=%d lie=%d cixu=%d\n",p,q,lie,cixu);
	if(q<=n){
		printf("%d %d",lie,q);
	}
	else{
		lie++;
		int hang=n-(q%n)+1;
		printf("%d %d",hang,lie);
	}
	return 0;
}
