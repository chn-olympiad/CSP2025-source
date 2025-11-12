#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],k,t,f[15][15],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,greater<int>());
    //for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			t=i;
			break;
		}
	}
	f[1][1]=a[1];
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				f[i][j]=a[++x];
				if(x==t){
					cout<<i<<' '<<j;
					return 0;
			    }
			}
		}else{
			for(int j=n;j>=1;j--){
				f[i][j]=a[++x];
				if(x==t){
					cout<<i<<' '<<j;
					return 0;	
				}
			}
		}
	}
}
