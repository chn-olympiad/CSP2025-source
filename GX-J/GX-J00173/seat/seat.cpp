#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int a[n][m],num = 0,R=b[0];
	sort(b,b+n*m,cmp);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				a[j][i]=b[num];
				num++;
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				a[j][i]=b[num];
				num++;
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(a[i][j]==R){
				cout<<j+1<<" "<<i+1;
			}
		}
	return 0;
}
