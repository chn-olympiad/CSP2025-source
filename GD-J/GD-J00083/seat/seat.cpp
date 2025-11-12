#include<bits/stdc++.h>
using namespace std;

const int N=15;
int n,m;
int a[N];
int sn[N][N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	
	int len=n*m;
	
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	
	
	int r=a[1];//a[1]为小R
	
	sort(a+1,a+len+1,cmp);
	
	int tot=1;
	
	for(int j=1;j<=m;j++){//列 
		if(j%2==1){//奇数列 
			
			for(int i=1;i<=n;i++){
				sn[i][j]=a[tot++];
			}
			
		}else{//偶数列 
			
			for(int i=n;i>=1;i--){
				sn[i][j]=a[tot++];
			}
			
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sn[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			} 
		}
	}
	
	return 0;
}
