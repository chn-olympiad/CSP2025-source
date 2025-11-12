#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[15][15];
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int New=a[1];
	sort(a+1,a+n*m+1,cmp);
	int sum=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				mp[i][j]=a[sum];
				sum+=1;					
			}
		}else if(i%2==0){
			for(int j=m;j>=1;j--){
				mp[i][j]=a[sum];
				sum+=1;
			} 
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==New){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 