#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,tmp,x,y=1;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(y&1){
			if(x==n) y++;
			else x++;
		}
		else{
			if(x==1) y++;
			else x--;
		}
		if(a[i]==tmp){
			printf("%d %d",y,x);
			return 0;
		}
	}
}
