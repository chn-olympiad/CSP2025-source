#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int u=a[0];
	int y=1;
	sort(a,a+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[y-1]==u){
				if(i%2!=0){
					cout<<i<<" "<<j;
					return 0;
				}else{
					cout<<i<<" "<<n+1-j;
					return 0;
				}
				return 0;
			}
			y++;
		}
	}
	return 0;
} 