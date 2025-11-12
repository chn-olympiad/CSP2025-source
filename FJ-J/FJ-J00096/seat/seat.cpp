#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int n,m,k=0;
int a[N];

bool cmp1(int x,int y){
	if(x>=y) return true;
	else return false;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+t,cmp1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==r){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[i*n-j+1]==r){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
