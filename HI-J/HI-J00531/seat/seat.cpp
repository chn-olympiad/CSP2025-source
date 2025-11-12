#include<bits/stdc++.h>
using namespace std;
int a[105];
int v[15][15];
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int s=a[1];
	sort(a+1,a+n*m+1,c);
	int k=1;
	//感谢ccf，感谢木，感谢这道题！！！ 
	//cout<<a[1]<<" ";
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				v[j][i]=a[k];
				if(a[k]==s){
					cout<<i<<' '<<j;
					return 0;
				}
			}else{
				v[n-j+1][i]=a[k];
				if(a[k]==s){
					cout<<i<<' '<<n-j+1;
					return 0;
				}
			}
			k++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<v[i][j]<<' ';
//		cout<<endl;
//	}
	return 0;//加油！！！！！！！
}

