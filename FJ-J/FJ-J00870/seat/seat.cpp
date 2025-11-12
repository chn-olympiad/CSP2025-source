#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[10005];
int cmp(int x,int y){
	return x>y;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int  n,m;
	cin>>n>>m;//n为行，m为列 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[(i-1)*m+j];	//输入 
		}
	}int cnt=b[1];
	sort(b+1,b+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<b[i]<<" ";
//	} 
	int k=1,f=1,i=1;//k为每一列最小的数字下标，f为存储在第几列，i为存储第几个数 
	while(1){
		if(k>n*m)break; 
		for(int j=k;j<k+n;j++){//每一组的第一列 
			a[j-k+1][f]=b[i];
			i++;
		}k+=n;
		if(k>n*m)break;
		f++;
		for(int j=k+n-1;j>=k;j--){// 每一组的第二列 
			a[j-k+1][f]=b[i];
			i++;
		}k+=n;
		f++;
	}for(int i=1;i<=n;i++){//判断位置 
		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
			if(a[i][j]==cnt){
				cout<<j<<" "<<i; 
			}
		}//cout<<endl;
	}return 0;
}
