#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],dis,x,y;
bool b[10001];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
		if(i==1) b[a[i]]=1;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[a[i]]==1) {
			dis=i;
			break;
		}
	}
	x=dis/n;
	y=dis%n;
	if(y!=0) x++;
	if(y==0) y=n;
	if(x%2==0) y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
