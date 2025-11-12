#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=1,x=1,y=1;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	sort(a+2,a+n*m+1,greater<int>());
	for(int i=2;i<=n*m;i++)
		if(a[t]<a[i]){
			swap(a[t],a[i]);
			t++;
		}
	while(t!=1){
		if(x%2==1)y++;
		else y--;
		if(y>n){
			x++;
			y--;
		}else if(y<1){
			x++;
			y++;
		}
		t--;
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}
