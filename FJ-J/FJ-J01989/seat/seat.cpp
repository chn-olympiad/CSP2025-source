#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],x[1000],y[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int l=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int z=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				l++;
				x[a[l]]=i;
				y[a[l]]=j;
			}
		}else{
			if(i%2==0){
				for(int j=n;j>=1;j--){
					l++;
					x[a[l]]=i;
					y[a[l]]=j;
				}
			}
		}
	}
	cout<<x[z]<<" "<<y[z];
	return 0;
}
