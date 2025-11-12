#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y=1;
int r,t,u;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(k<n*m){
		k++;
		if(y%2==1){
			x++;
		}else{
			x--;
		}
		if(x<1){
			y++;
			x=1;
		}else{
			if(x>n){
				y++;
				x=n;
			}
		}
		if(a[k]==r){
			t=y;
			u=x;
			break;
		}
	}
	cout<<t<<" "<<u;
	return 0;
}
