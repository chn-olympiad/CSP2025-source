#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int r,n,m,a[101]={},l;
	cin>>n>>m;
	l=n*m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=l;i++){
		cin>>a[i];
	}
	sort(a+1,a+l+1,cmp);
	l=1;
	for(int c=1;c<=m;c++){
		if(c%2==1){
			for(int j=1;j<=n;j++){
				if(a[l]==r){
					cout<<c<<" "<<j;
					return 0;
				}
				l++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[l]==r){
					cout<<c<<" "<<j;
					return 0;
				}
				l++;
			}
		}
	}
	return 0;
} 
