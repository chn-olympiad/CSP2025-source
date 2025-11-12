#include<bits/stdc++.h>
using namespace std;
int a[105],cnt,n,m;
bool f;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,x=1,y=1;;i++){
		if(a[i]==cnt){
			printf("%d %d\n",y,x);
			return 0;
		}bool t=y%2;
		if(t and x!=n and !f)x++;
		else if(!t and x!=1 and !f)x--;
		else if(!f)y++,f=true;
		else if(t and f)x++,f=false;
		else if(!t and f)x--,f=false;
	}
}
