#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],o;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>o;
	a[1]=o;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			cout<<(i+m-1)/m;
			if(((i+m-1)/m)%2==1)cout<<' '<<(i-1)%m+1;
			else cout<<' '<<n-(i-1)%m;
		}
	}
	return 0;
}