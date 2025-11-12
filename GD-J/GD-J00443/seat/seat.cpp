#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[1005],sum,d[15][15],l,r,b;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			s=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				d[i][j]=a[sum++];
				if(a[sum]==s){
					l=i;
					r=j;
					b=1;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				d[i][j]=a[sum++];
				if(a[sum]==s){
					l=i;
					r=j;
					b=1;
				}
			}
		}
		if(b==1){
			break;
		}
	}
	cout<<l<<" "<<r;
	return 0;
} 
