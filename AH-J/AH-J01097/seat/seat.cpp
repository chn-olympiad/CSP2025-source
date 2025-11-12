#include<bits/stdc++.h>
using namespace std;
const int INF=110;
int n,m,a[INF];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n*m; i++)
		scanf("%d",&a[i]);
	int h=a[1];
	sort(a+1,a+n*m+1,cmp);
	int g=-1;
	for(int i=1; i<=n*m; i++){
		if(a[i]==h){
			g=i;
			break;
		}
	}
	int f1=g/n,f2=g%n;
	if(f2!=0) f1++;
	if(f2==0&&f1%2==1) f2=n;
	else if(f2==0&&f1%2==0) f2=1;
	else if(f1%2==0) f2=n-f2+1;
	printf("%d %d",f1,f2);
	return 0;
}
