#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,cnt,a[10005],b[105][105],k=1;
bool cmp(int x,int y){
	return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		cnt=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=a[k];
			k++;
			}
		
		
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==cnt){
				cout<<i<<" "<<j;
				return 0;}
			}
		
		
		}
	
	return 0;
}
