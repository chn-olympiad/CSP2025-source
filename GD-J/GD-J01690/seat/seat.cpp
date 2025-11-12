#include<bits/stdc++.h>
using namespace std;
int a[505];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,ri;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R)ri=i;
	}
	int x,y;
	if(ri/n*n!=ri)x=ri/n+1;
	else x=ri/n;
	if(x%2==0){
		if(ri%n==0)y=1;
		else y=n-ri%n+1;
	}else{
		if(ri%n==0)y=n;
		else y=ri%n;
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

