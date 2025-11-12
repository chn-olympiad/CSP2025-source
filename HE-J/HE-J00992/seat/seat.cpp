#include<bits/stdc++.h>
using namespace std;
int a;
int n,m;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			cin>>a;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int w=a[1];
			sort(a+n+1,a+n);
			w=sort(a[1+1],a[1]);
			if(w-n<=0&&w%m>=0){
				c=1;
				r=a[w];
			}
			if(w-n>0){
				c=w+n-n;
				r=c;
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
