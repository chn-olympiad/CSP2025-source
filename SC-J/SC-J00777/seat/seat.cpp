#include<bits/stdc++.h>
using namespace std;
int arr[150][150];
int brr[15000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//写freopen(注意空格！！！),提交记得注释，换行用"\n"!!! fc来对比！记得对拍! 
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>brr[i];
	}
	int ans=brr[1];
	sort(brr+1,brr+1+n*m,cmp);
	int idx=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				idx++;
				arr[j][i]=brr[idx];
			}
		}else{
			for(int j=m;j>=1;j--){
				idx++;
				arr[j][i]=brr[idx];				
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}

	}			
	return 0;
} 