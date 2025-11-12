#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int s,cnt=1;
	scanf("%d",&s);
	for(int i=2;i<=n*m;i++){
		int x;
		scanf("%d",&x);
		if(x>s) cnt++;
	}
	int a=cnt/n,b=cnt%n;
	if(b!=0) a++;
	else b=n;
	if(a%2==0) b=n-b+1;
	printf("%d %d\n",a,b);
}
