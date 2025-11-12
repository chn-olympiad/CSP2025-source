#include<bits/stdc++.h>
using namespace std;
int n,m,r,zuo,lie;
int a[150];
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
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i+1]==r){
			lie=i/n+1;
			zuo=i%n+1;
			if(lie%2){
				cout<<lie<<" "<<zuo;
				break;
			}
			else{
				cout<<lie<<" "<<n-zuo+1;
				break;
			}
		}
	}
	return 0;
}