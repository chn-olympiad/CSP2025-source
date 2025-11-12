#include<bits/stdc++.h>
using namespace std;
const int N=12;
bool cmp(int x,int y){
	return x>y;
}
int n,m,t,a[N*N],ans,x,y;
int k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int t=n*m;
	for(int i=1;i<=t;i++) scanf("%d",a+i);
	ans=a[1];
	sort(a+1,a+t+1,cmp);
	x=1,y=1,k=1;
	for(int i=1;i<=t;i++){
		if(a[i]==ans){
			cout<<y<<' '<<x;
			return 0;
		}
		x+=k;
		if(x>n||x==0){
			x-=k;
			y++;
			k=-k;
		}
	}
	return 0;
}
