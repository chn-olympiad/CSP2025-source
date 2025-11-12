#include<bits/stdc++.h>
using namespace std;
int n,m,y,a[205];
bool cmp(int x,int z){
	return x>z;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	cin >>a[1];
	y=a[1];
	for(int i=2;i<=n*m;i++){
		cin >>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==y){
		y=i;
		break;	
		}
	}
	int qaz=y/n;
	int wsx=y%n;
	if(wsx==0){
		cout<<qaz<<" ";
		if(qaz%2==1){
			cout<<1;
		}else {
			cout<<n;
		}
	}else{
		cout<<qaz+1<<" ";
		if(qaz%2==0){
			cout<<wsx;
		}else {
			cout<<n-wsx+1;
		}
	}
	return 0;
}
