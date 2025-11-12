#include<bits/stdc++.h>
using namespace std;
int a[110],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>r;a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m/2;i++)swap(a[i],a[n*m-i+1]);
	int x=1,y=1;
	for(int i=1;a[i]!=r;i++){
		if(y==1&&x%2==0){
			x++;
		}
		else if(y==n&&x%2==1){
			x++;
		}else if(x%2==1){
			y++;
		}else {y--;
		}
		
		
	}
	cout<<x<<" "<<y;
	return 0;
}
