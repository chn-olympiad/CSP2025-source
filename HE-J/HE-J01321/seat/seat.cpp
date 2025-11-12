#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,c,r,tot;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int tmp=a[1],id;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++){
				if(a[++tot]==tmp){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		else
			for(int j=n;j>=1;j--){
				if(a[++tot]==tmp){
					cout<<i<<" "<<j;
					return 0;
				}
			}}	
	return 0;
}
