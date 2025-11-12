#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m,cmp);
	int p=0,z=0;
	for(int i=1;i<=m;i++){
		if(p==1){
			for(int j=n;j>=1;j--){
				if(a[z]==b){
					cout<<i<<" "<<j;
					return 0;
				}
				z++;
			}
			p=0;
		}
		else{
			for(int j=1;j<=n;j++){
				if(a[z]==b){
					cout<<i<<" "<<j;
					return 0;
				}
				z++;
			}
			p=1;
		}
	}
	return 0;
}
