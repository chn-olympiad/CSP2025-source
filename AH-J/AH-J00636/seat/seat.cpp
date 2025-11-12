#include<iostream>
#include<algorithm>
using namespace std;
bool o(int x,int y){
	return x>y;
}
int sum;
int n,m;
int  a[105];
int f[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+sum,o);
	int s=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				f[j][i]=a[++s];
				if(a[s]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				f[j][i]=a[++s];
				if(a[s]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
