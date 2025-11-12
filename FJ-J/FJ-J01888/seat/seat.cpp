#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],t,x,y;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==t){
			t=i;
			break;
		}
	x=(t-1)/n+1;
	t%=n;
	if(t==0)
		t=n;
	if(x%2==1)
		y=t;
	else
		y=n-t+1;
	cout<<x<<" "<<y;
	return 0;
} 
