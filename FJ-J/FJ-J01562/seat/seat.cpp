#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,ses;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) ses=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*m+j]==ses){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		} 
		else{
			for(int j=1;j<=n;j++){
				if(a[(i-1)*m+j]==ses){
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}

/*
2 2
99 100 97 98

*/
