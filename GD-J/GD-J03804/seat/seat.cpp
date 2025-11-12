#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,a[N],idx;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int f=a[1]; 
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f)idx=i;
	}
	for(int i=0;i<m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(idx==i*n+j){
					cout<<i+1<<' '<<n-j+1;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(idx==i*n+j){
					cout<<i+1<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
