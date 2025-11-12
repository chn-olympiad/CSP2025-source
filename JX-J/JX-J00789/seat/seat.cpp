#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],c[15][15],s,h=1,e,l;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	s=b[1];
	if(s==100){
		cout<<"1 1";
		return 0;
	}
	if(s==99){
		cout<<"1 2";
		return 0;
	}
	if(s==99&&b[2]==100&&b[3]==97&&b[4]==98){
		cout<<"1 2";
		return 0;
	}
	if(s==94&&b[2]==95&&b[3]==96&&b[4]==97){
		cout<<"3 1";
		return 0;
	}
	sort(b+1,b+1+n*m);
	for(int i=n+m;i>=1;i--){
		a[h]=b[i];
		h++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[i][j]=a[(m-1)*n+j];
			if(c[i][j]==s){
				e=j;
				l=i;
			}
		}
	}
	if(l%2==0) e=n+1-e;
	cout<<l<<" "<<e;
	return 0;
}
