#include <bits/stdc++.h>
using namespace std;
int n,m,s;
int x,y,f;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	x=1,y=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	s=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			printf("%d %d",y,x);
			return 0;
		}
		if(x==n && f==0) y++,f=1;
		else if(x==1 && f==1) y++,f=0;
		else if(f==0) x++;
		else x--;
	}
	return 0;
}
