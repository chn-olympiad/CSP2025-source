#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n*m+5]={0};
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int yr=a[1],x=0,y=1,f=1,ans=0;
	sort(a+1,a+n*m+1,cmp);
	while(1){
		x+=f;ans++;
		if(x>n){
			x=n;y++;
			f=-1;
		}else if(x<1){
			x=1;y++;
			f=1;
		}if(a[ans]==yr){
			cout<<y<<" "<<x;
			return 0; 
		}
	}
	return 0;
}
