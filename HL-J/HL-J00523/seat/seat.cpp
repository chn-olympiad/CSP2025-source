#include<bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,q,x;
	cin>>n>>m;
	q=m*n;
	int b[20][20];
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	x=a[1];
	int j=0,h=0;
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				h++;
				if(a[h]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int r=n;r>=1;r--){
				h++;
				if(a[h]==x){
					cout<<i<<" "<<r;
					return 0;
				}
			}
		}
	}
	return 0;
}

