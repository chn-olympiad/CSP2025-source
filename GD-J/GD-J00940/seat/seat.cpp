#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,k,ct=0,dq=0;
	cin>>n>>m;
	int a[n*m+1]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)k=a[i];
	}
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int b[n+1][m+1]={0};
	for(int i=1;i<=m;i++){
		ct++;
		if(ct%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++dq];
				if(a[dq]==k){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[++dq];
				if(a[dq]==k){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
//    for(int i=1;i<=n;i++){
//    	for(int j=1;j<=m;j++){
//    		cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
