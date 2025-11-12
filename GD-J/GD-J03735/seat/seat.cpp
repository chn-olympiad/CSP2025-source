#include<bits/stdc++.h>
using namespace std;
int n,m,q[110],xm;//n行数m列数 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>q[1];
	xm = q[1];
	for(int i = 2;i<=n*m;i++){
		cin>>q[i];
	}
	int c= 1,r = 1,a = 1,i = n*m;//c列r行 
	sort(q+1,q+n*m+1);
	for(c = 1;c<=m;c++){
		for(int j = 1;j<=n;j++,i--){
			if(r == n&&a==1){
				a = -1;
			}
			if(r==1&&a==-1){
				a = 1;
			}
			
			if(q[i]==xm){
				cout<<c<<' '<<r;
				return 0;
			}
			if(j!=n)r+=a;
		}
	}
	return 0;
}
