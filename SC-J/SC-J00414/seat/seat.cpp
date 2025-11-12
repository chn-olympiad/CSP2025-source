#include<bits/stdc++.h>

using namespace std;
const int  N=1e6+10; 
int n,m,a[N],c,r ;
int tot=0,cnt;
int main(){
//	freopen ("number.in","r",stdin);
//	freopen ("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		tot++;
		cin>>a[i];
		int cnt=a[1];
		if(a[1]<a[i-1]){
			a[1]=a[i-1];
		}
		cout<<i<<endl;
		if(i%m==0){
			c=i/m;
		}else if(i%m!=0){
			c=i/m+1;
		}
		
		if(n%i==0){
			r=n;
		}else if(n%i!=0){
			r=n/i+1;
		}
	}
	cout<< c<<" "<<r;
	return 0;
} 