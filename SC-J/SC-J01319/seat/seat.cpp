#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=11;
int a[N*N]; 
int n,m,R,c,r,h=1,l=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	sort(a,a+n*m);
	int x=lower_bound(a,a+n*m,R)-a;
//	if(!x%n){
//		if(x/n%2==0) c=1,r=x/n;
//		else c=n,r=x/n;
//	}else{
//		if(!x/n%2) c=x%n,r=x/n+1;
//		else c=n-x%n+1,r=x/n+1;
//	}
	if(x==n*m-1){
		cout<<1<<' '<<1<<endl;
		return 0;
	} 
	int pxl=1;
	for(int i=n*m-1;i>x;i--){
		//cout<<pxl<<' '<<l<<' '<<h<<endl;
		if(h==n&&pxl==1){
			pxl=-1,l++;
		}else if(h==1&&pxl==-1){
			pxl=1,l++;
		}
		else h+=pxl;
		//cout<<pxl<<' '<<l<<' '<<h<<endl;
	}
	cout<<l<<' '<<h<<endl;
	return 0;
}