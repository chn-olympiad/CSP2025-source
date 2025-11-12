#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=m;++i)
#define ref(i,n,m) for(int i(n);i>=m;--i)
using namespace std;
int a[205],tot;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p;
	cin>>n>>m;
	rep(i,1,n*m) cin>>a[i];
	p=a[1];
	a[0]=0x3f3f3f3f;
	sort(a+1,a+n*m+1,cmp);
//	rep(i,1,n*m) cout<<a[i]<<" ";
	for(int i=1;i<=m;i+=2){
//		cout<<a[(i-1)*n]<<" "<<a[(i+1)*n]<<"\n";
		if(a[(i-1)*n]>p&&p>=a[(i+1)*n]){
			int R=0,C=0;
			rep(j,1,n){
//					cout<<i<<" "<<j<<" "<<a[(i-1)*n+j]<<"\n";
				if(a[(i-1)*n+j]==p){
					R=i;
					C=j; 
				}	
			} 
			ref(j,n,1){
//					cout<<i<<" "<<j<<" "<<a[i*n+j]<<"\n";
				if(a[i*n+n-j+1]==p){
					R=i+1;
					C=j;
				}
			}
			cout<<R<<" "<<C;
			return 0;
		}
	}
	return 0;
}
