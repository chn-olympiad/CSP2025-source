#include<bits/stdc++.h>
using namespace std;
long long n,m,a[102][102],b[10004],rw,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	swap(n,m);
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1) rw=b[i];
	}
	sort(b+1,b+1+n*m);
	s=n*m;
	for(int i=1;i<=n;i++){
		if(i%2==1) for(int j=1;j<=m;j++) a[i][j]=b[s--];
		else for(int j=m;j>=1;j--) a[i][j]=b[s--];
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==rw){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
