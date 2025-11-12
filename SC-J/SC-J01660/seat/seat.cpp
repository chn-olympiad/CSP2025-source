#include<bits/stdc++.h>
using namespace std;
int a[107],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+n*m+1,cmp);
	int chenji=0;
	for(int i=1;i<=n*m;i++)
		if(a[0]==a[i])
			chenji=i;
	int up=0,x=1,y=1;
	for(int i=1;i<=m;i++){
		x=i,up=!up;	
		chenji--;
		if(chenji==0){
			cout<<x<<" "<<y<<endl;
			return 0;
		}
		for(int j=1;j<n;j++){
			if(up==1)
				y++;
			else
				y--;
			chenji--;
			if(chenji==0){
				cout<<x<<" "<<y<<endl;
				return 0;
			}
		}
	}
	return 0;
}