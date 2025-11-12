#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int a[100001]={0},b[100001][100001]={0};
int sum;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=0;i<sum;i++){
		cin>>a[i];
	}
	int r=a[0];
	int c=0;
		sort(a,a+sum,cmp);
		int i=0,j=0;
		for(i=0;i<m;i++){
			for(j=0;i<n;i++){
				b[i][j]=a[c];
				c++;
			}
		}
		i=0;
		j=0;
		for(i=0;i<m;i++){
			for(j=0;j<n;i++){
				if(b[i][j]==r){
					cout<<j+1<<" "<<i+1;
					return 0;
				}
			}
		}
	return 0;
}
