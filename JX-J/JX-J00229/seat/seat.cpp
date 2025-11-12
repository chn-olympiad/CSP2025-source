#include<bits/stdc++.h>
using namespace std;
int n,m,t,w,x,y;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			w=i;
			break;
		}
	}
	x=(w-1)/n+1;
	if(x%2==1)y=w-(x-1)*n;
	else y=n-(w-(x-1)*n)+1;
	cout<<x<<' '<<y;
	return 0;
}
