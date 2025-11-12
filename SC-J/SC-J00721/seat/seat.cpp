#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,num,sum;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)num=a[1];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==num)sum=n*m-i+1;
	}
	int x=sum/(2*n)*2;
	int y=sum%(2*n);
	if(y==0){
		cout<<x<<" "<<1;
	}else if(y<=n&&y!=0){
		cout<<x+1<<" "<<y;
	}else{
		cout<<x+2<<" "<<2*n-y+1;
	}
	return 0;
}