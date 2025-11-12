#include<bits/stdc++.h>
using namespace std;

int n,m;
int num,res;
int x,y;
int r;
int arr[105];
int seat[15][15];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>arr[i];
	}
	r=arr[1]; res=1;
	sort(arr+1,arr+num+1,cmp);
	for(int i=1;i<=n;i++){
		if((res/n)%2==0){
			for(int j=1;j<=m;j++){
				seat[i][j]=arr[res];
				res++;
			}
		}else{
			for(int j=m;j>=1;j--){
				seat[i][j]=arr[res];
				res++;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<seat[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==r){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
