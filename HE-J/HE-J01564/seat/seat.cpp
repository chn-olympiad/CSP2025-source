#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int a[N];
int s[N];
int e[20][20];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==cnt){
			cnt=i;
			break;
		}
	}
	e[1][1]=1;
	for(int i=1;i<=n;i++){
		if(i==1){
			for(int j=1;j<=m;j++){
				if(j==1){
					continue;
				}
				if(j%2==0){
					e[i][j]=j*n;
				}else{
					e[i][j]=e[i][j-1]+1;
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				if(j%2==1){
					e[i][j]=e[i-1][j]+1;
				}else{
					e[i][j]=e[i-1][j]-1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(e[i][j]==cnt){
				cout<<j<<" "<<i<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
