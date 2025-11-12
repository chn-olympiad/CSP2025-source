#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],c,k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	c=a[1];
	sort(a+1,a+k+1,cmp);
	int oo=0;
	for(int i=1;i<=k;i++){
		if(a[i]==c){
			oo=i;
			break;
		}
	}
	int x=1,y=1;
	while(oo>1){
		if(x%2==1){
			y++;
			if(y==n+1){
				y=n;
				x++;
			}
		}
		else {
			y--;
			if(y==0){
				y=1;
				x++;
			}
		}
		oo--;
	}cout<<x<<" "<<y<<"\n";
	return 0;
}
