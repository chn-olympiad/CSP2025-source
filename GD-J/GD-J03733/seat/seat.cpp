#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=0;
	for(k=1;k<=m*n;k++) cin>>a[k];
	int R=a[1];
	sort(a+1,a+k+1,cmp);
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				cnt++;
				if(a[cnt]==R){
					cout<<j<<" "<<i;
					return 0;
				}
			}
	 	}
		else if(j%2==0){
			for(int i=n;i>=1;i--){
				cnt++;
				if(a[cnt]==R){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
