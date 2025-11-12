#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],r,s,len;
int se[12][12];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());

	int flag=1;
	for(int l=1;l<=m;l++){
		flag^=1;
		if(flag==0){
			for(int h=1;h<=n;h++){
				se[h][l]=a[++len];
			}
		}else{
			for(int h=n;h>=1;h--){
				se[h][l]=a[++len];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(se[i][j]==r){
				cout<<j<<" "<<i;
				//注意是先输出  “列 ” ，在输出  “行 ” 
				return 0;
			}
		}
	}
	return 0;
} 
