#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[107];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,op=0,tp=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[tp]==ans){
				cout<<y<<" "<<x;
				return 0;
			}
			tp++;
			if(op==0) x=min(x+1,n);
			else x=max(x-1,1);
		}
		y++;
		op=(op+1)%2;
	}
	return 0;
}
