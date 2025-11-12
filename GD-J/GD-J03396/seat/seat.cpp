#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int seat=a[1];
	int cnt=1;
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				//cout<<a[cnt]<<endl;
				if (a[cnt++]==seat){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for (int j=n;j>=1;j--){
				if (a[cnt++]==seat){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}

	}
	return 0;
}
