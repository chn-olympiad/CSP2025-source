#include<bits/stdc++.h>
using namespace std;
int a[101],b[101][101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			if(i%m==0){
				c=i/m;
				r=m;
			}
			else{
				c=i/m+1;
				r=i%m;
			}
			if(c%2==0){
				cout<<c<<" "<<m-r+1;	
			}
			else{
				cout<<c<<" "<<r;
			}
		}
	}
	return 0;
}
