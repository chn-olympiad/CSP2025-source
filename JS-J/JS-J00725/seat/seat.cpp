#include<bits/stdc++.h>
using namespace std;
int n,m,r,sx,sy;
int a[1010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i])r=i;
	}
	sy=(r-1)/n+1;
	if(sy%2==1){
		if(r%n==0)sx=n;
		else sx=r%n;
	}else{
		if(r%n==0)sx=1;
		else sx=n-(r%n)+1;
	}
	cout<<sy<<" "<<sx<<endl;
	return 0;
}

