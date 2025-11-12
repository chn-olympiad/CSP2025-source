#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	int tg=a[1];
	sort(a+1,a+n*m+1,cmp);
	int s;
	for(int i=1;i<=n*m;++i)
		if(a[i]==tg){
			s=i;break;
		}
	int tx=s/(2*n),ty=s%(2*n),x,y;
	if(!ty)x=tx*2,y=1;
	else if(ty<=n)x=tx*2+1,y=ty;
	else ty-=n,x=tx*2+2,y=n-ty+1;
	cout<<x<<" "<<y;	

	return 0;
}

