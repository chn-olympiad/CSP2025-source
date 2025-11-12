#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int x,y;
};
bool cmp(aaa x,aaa y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	aaa a[200];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;	
	}
	int sum=1;
	sort(a+1,a+1+(n*m),cmp);
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				if(a[sum].y==1){
					cout<<j<<" "<<i;
					return 0;
				}
				sum+=1;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[sum].y==1){
					cout<<j<<" "<<i;
					return 0;
				}
				sum+=1;
			}
		}
	}
	return 0;
}
