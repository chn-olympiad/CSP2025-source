#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],r,x=0,y=1;
bool cmp(int a1,int b1){
	return a1>b1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(y%2==1) x++;
		else x--;
		if(x==n+1) x--,y++;
		if(x==0) x++,y++;
		if(a[i]==r){
			cout<<y<<" "<<x;
			break;
		}
	}
	return 0;
}
