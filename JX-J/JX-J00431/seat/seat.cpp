#include<bits/stdc++.h>
using namespace std;
int a[105];
int dx[]={-1,1};
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1],cnt=1,x=1,y=1;
	sort(a+1,a+1+n*m,cmp);
	while(a[cnt]>ans){
		cnt++;
		if(x==n&&y%2==1){
			y++;
			continue;
		}
		if(x==1&&y%2==0){
			y++;
			continue;
		}
		x+=dx[y%2];
	}
	cout<<y<<" "<<x;
	return 0;
}
