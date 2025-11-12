#include<bits/stdc++.h>
using namespace std;
int a[10+5][10+5];
int numbers[15*15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>numbers[i];
	}
	int r=numbers[0];
	sort(numbers,numbers+n*m);
	int tmp=n*m-1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[j][i]=numbers[tmp--];
			}
		}else{
			for(int j=1;j<=n;j++){
				a[j][i]=numbers[tmp--];
			}
		}
	}
	int xx=0,yy=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==r){
				yy=i;
				xx=j;
			}
		}
	}
	cout<<xx<<" "<<yy;
	return 0;
} 
