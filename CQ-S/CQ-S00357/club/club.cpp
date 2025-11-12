#include<bits/stdc++.h>
#define ll long long
using namespace std; 
bool fi(int x,int y){return x>y;}
int t,n,aa[11451][4];
ll bb,num=0;
void QWQ(int x,int sum,int a,int b,int c,int y){
	if(a>(n/2)||b>(n/2)||c>(n/2))return;
		if(x>n){
			sum+=aa[x][y];
			if(bb<sum)bb=sum;
			return;
		}
		QWQ(x+1,sum+aa[x][1],a+1,b,c,1);
		QWQ(x+1,sum+aa[x][2],a,b+1,c,2);
		QWQ(x+1,sum+aa[x][3],a,b,c+1,3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bb=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&aa[i][1],&aa[i][2],&aa[i][3]);
		}
		QWQ(1,0,0,0,0,1);
		printf("%d\n",bb);
	}
	return 0; 
}
