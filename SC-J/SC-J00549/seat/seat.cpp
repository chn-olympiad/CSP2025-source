#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	memset(a,0,sizeof(a));
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int tip=a[1];
	sort(a+1,a+1+n*m,cmp);
	int sum=1,x=1,y=1;
	while(a[sum]!=tip){
		if(y%2==1){
			if(x!=n)x++;
			else y++;
		}
		else{
			if(x!=1)x--;
			else y++;
		}
		sum++;
	}
	cout<<y<<" "<<x;
	return 0;
}