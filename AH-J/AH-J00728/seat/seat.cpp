#include<bits/stdc++.h>
using namespace std;
int n,m,x,sum=1;
int a[110];
int b[20][20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2==1){
				x=i;
			}
			else if(j%2==0){
				x=n-i+1;							
			}
			b[x][j]=a[sum];
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==s){
				cout<<j<<" "<<i;
			}
		}
	}
    return 0;
}
