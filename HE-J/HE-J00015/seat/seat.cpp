#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+m*n+1,cmp);
	int j;
	for(int i=1;;i++){
		if(x==a[i]){
			j=i;
			break;
		}
	}
	int c=j/m+1;
	if(j%m==0)c--;
	if(c%2==1){
		if(j%n==0){
			cout<<j/m<<' '<<n; 
		}
		else{
			cout<<j/m+1<<' '<<j%m;
		}
	}
	else{
		if(j%n==0){
			cout<<j/m<<' '<<1;
		}
		else{
			cout<<j/m+1<<' '<<n-j%n+1;
		}
	}
	return 0;
}
