#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,wz;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 	cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			wz=i;
			break;
		}
	}
	int x=0,y=0;
	if(wz%n!=0) x=(wz/n)+1,y=wz%n;
	else x=wz/n,y=n;
	if(x%2==1){
		cout<<x<<" "<<y;
	}
	else{
		cout<<x<<" "<<(n-y)+1;
	}
	return 0;
} 
