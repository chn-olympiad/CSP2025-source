#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	int n,m,w,a[110],c[20][20],x=1;
	cin>>n>>m;
	w=n*m;
	for(int i=1;i<=w;i++) cin>>a[i];
	int cnt=a[1];
	sort(a+1,a+1+w,cmp);
	int i=1;
	for(int k=1;k<=n;k++){
		if(x%2!=0){
			for(int j=1;j<=m;j++){
				if(i!=w){
					c[j][k]=a[i];
				}
				i++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(i!=w){
					c[j][k]=a[i];
				}
				i++;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int j=1;j<=m;j++){
			if(c[k][j]==cnt){
				cout<<j<<" "<<k;
				return 0;
			}	
		}
	}
}
