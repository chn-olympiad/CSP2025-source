#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int s=a[1];
	//cout<<s<<endl;
	sort(a,a+n*m+1);
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<' ';
	h=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(s==a[h]){
					cout<<i<<' '<<j;
					return 0;
				}
				h--;
			}
		}
		else {
			for(int j=1;j<=n;j++){
				if(s==a[h]){
					cout<<i<<' '<<j;
					return 0;
				}
				h--;
			}
		}
	}
	return 0;
}