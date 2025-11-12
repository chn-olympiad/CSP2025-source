#include <bits/stdc++.h>
using namespace std;

const int N=110;
int n,m,xiaoR1;
int a[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaoR1=a[1];
	sort(a+1,a+n*m+1,cmp);
	int xiaoR2;
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaoR1){
			xiaoR2=i;
			break;
		}
	}
	int x=xiaoR2/n;
	if(xiaoR2%n!=0) x+=1;
	int c,r;
	c=x;
	if(x%2==1){
		r=n-n*x+xiaoR2;
	}else{
		r=n*x-xiaoR2+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
