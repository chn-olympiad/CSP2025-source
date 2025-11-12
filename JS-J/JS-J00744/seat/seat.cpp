#include <bits/stdc++.h>
using namespace std;
int a[1001];
int n,m;
int cnt;
int xm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+(n*m)+1);
	bool f=1;
	/*cout<<xm<<'\n';
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";*/
	for(int j=1;j<=m;j++){
		f^=1;
		for(int i=1;i<=n;i++){
			cnt++;
			if(a[n*m-cnt+1]==xm){
				if(f==0){
					cout<<j<<" "<<i;
				}else{
					cout<<j<<" "<<n-i+1;
				}
				return 0;
			}
		}
	}
	return 0;
}
