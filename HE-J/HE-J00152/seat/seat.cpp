#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}int a[1000];
int ans[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0)r=a[i];
	}
	sort(a,a+n*m,cmp);
	int i=0;
	int x=0,y=0;
	while(i<n*m){
		for(;x<n;x++){
			ans[x][y]=a[i];
			i++;
		}
		y++;
		x--;
		for(;x>=0;x--){
			ans[x][y]=a[i];
			i++;
		}
		y++;
		x++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		//	cout<<ans[i][j]<<' ';
			if(ans[i][j]==r){
				cout<<j+1<<' '<<i+1;
				return 0;
			}
			
		}
	//	cout<<endl;
	}
	return 0;
}
