#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m*n];
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	int R=a[0];
	sort(a,a+m*n,cmp);
	int i=0,j=m*n-1,k;
	while(j>i){
		int sum=(i+j)/2;
		if(a[sum]>R)i=sum+1;
		else if(a[sum]<R)j=sum-1;
		else if(a[sum]==R){
			k=sum;
			break;
		}
	}
	k++;
	int x=k%(n*2),y=k/(n*2);
	if(x<=n)cout<<y*2+1<<" "<<x;
	else{
		cout<<(y+1)*2<<" "<<2*n-x+1;
	}
	return 0;
}
