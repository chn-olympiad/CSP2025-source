#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	int num=a[1],id=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			id=i;
			break;
		}
	}
	int r=id%n+(id%n==0)*n,c=id/n+(id%n!=0);
	if(c%2==0)	r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}