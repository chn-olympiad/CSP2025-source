#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x=1,y=1,c=1;
	while(1){
		if(a[c]==t)break;
		if(x&1){
			if(y==n)x++;
			else y++;
		}else{
			if(y==1)x++;
			else y--;
		}
		c++;
	}
	cout<<x<<" "<<y;
	return 0;
}
