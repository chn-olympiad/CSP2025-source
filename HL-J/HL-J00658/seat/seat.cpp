#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=100;
int q[N][N],a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt%2==0){
			for(int j=1;j<=n;j++){
				q[i][j]=a[j+cnt*n];
				if(q[i][j]==r){
					cout<<i<<" "<<j<<endl;
					break;
				} 
			}
		}
		else{
			for(int j=n,j1=1;j>=1;j--,j1++){
				q[i][j]=a[j1+cnt*n];
				if(q[i][j]==r){
					cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}
		cnt++;
	}
	return 0;
}
