#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105],R,idx,b[105];
int shexing[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
		if(i==1){
			R=a[i];//记录R的成绩 
		}
	}
	
	sort(a+1,a+n*m+1);//排序 (升序)
	
	for(int i=n*m,j=1;i>=1,j<=n*m;i--,j++){
		if(a[i]==R){
			idx=j;//记录名次 
		}
		b[j]=a[i];//倒回来 
	}
	int s=1;
	for(int i=1;i<=m,s<=n*m;i++){//模拟
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				shexing[j][i]=b[s++];
			}
		}else{
			for(int j=n;j>=1;j--){
				shexing[j][i]=b[s++];
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(shexing[j][i]==R){
				cout<<i<<' '<<j;
			}//cout<<shexing[j][i]<<' ';
		}
	}
	return 0;
}
