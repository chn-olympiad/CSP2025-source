#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[1005],sum,b[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>m>>n;
	int sun=m*n+1;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int pro=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n;i++){
		++sum;
		if(sum%2==1){
			for(int j=1;j<=m;j++){
				--sun;
				//cout<<a[sun]<<endl;
				if(a[sun]==pro){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				--sun;
				//cout<<a[sun]<<endl;
				if(a[sun]==pro){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}