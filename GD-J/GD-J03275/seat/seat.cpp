#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+n*m+1,cmp);

	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			k=i;
			break;
		}
	}
	int x=0,y=1;
	//cout<<k;
	while(k){
		if((x==n&&y%2==1)||(x==1&&y%2==0)){
			y++;
			k--;
		}
		else if(y%2==1){
			x++;
			k--;
		}
		else if(y%2==0){
			x--;
			k--;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
