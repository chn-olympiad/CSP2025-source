#include<bits/stdc++.h> 
using namespace std;
int n,m,xr,sr,l,r;
int a[105];
int s[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>xr;
	a[1]=xr;
	for(int i=2;i<n*m;i++){
		cin>>a[i];
	}sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<n*m;i++){
		if(a[i]==xr){
			sr=i;
			break;
		}
	}l=1;r=0;
	for(int i=1;i<=sr;i++){
		if(l%2==1){
			if(r<n){
				r++;
			}else{
				l++;
			}
		}else{
			if(r>1){
				r--;
			}else{
				l++;
			}
		}
	}cout<<l<<' '<<r;
	return 0;
}
