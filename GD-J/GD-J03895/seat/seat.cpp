#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
		}
	}
	int cmp=0;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				cmp++;
				if(cmp==r){
					cout<<i<<' '<<j;
				}
			}
		}
		if(i%2==0){
			for(int j=n;j>0;j--){
				cmp++;
				if(cmp==r){
					cout<<i<<' '<<j;
				}
			}
		}
	}
	
}
