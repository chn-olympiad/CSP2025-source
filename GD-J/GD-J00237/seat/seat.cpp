#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[144],b[144];
	bool fo=0;
	int mp[12][12];
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int h=a[1];
	sort(a+1,a+n*m+1,cmp);
	int v=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				mp[i][j]=a[v];
				if(a[v]==h) cout << i << " " << j;
				v++;
			}
		}else{
			for(int j=m;j>=1;j--){
				mp[i][j]=a[v];
				if(a[v]==h) cout << i << " " << j;
				v++;
			}
		}
	}
	return 0;
} 
