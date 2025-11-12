#include<bits/stdc++.h>
using namespace std;
const int N=1e3+33;
int n,m,r;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<(n*m);i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	int x=0,y=0;
	for(int i=1;i<(n*m);i++){
		if(a[i]<r){
			if(i%n!=0){
				x=(i/n)+1;
			}else{
				x=i/n;
			}
			int z=i%n;
			if(x%2==0){
				if(z==0){
					y=1;
				}else{
					y=n-z+1;
				}
			}else{
				if(z==0){
					y=n;
				}else{
					y=z;
				}
			}
			cout<<x<<" "<<y;
			return 0;
		}
	}
	cout<<m<<" "<<n;
	return 0;
}
