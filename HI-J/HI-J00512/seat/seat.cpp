#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int mapn[15][15];
int n,m;
int ansn,ansm;
void swapn(void){
	int cnt=0;
	for(int i=n*m;i>=1;i--){
		b[++cnt]=a[i];
	}
	return ;
}
void px(void){
	int cnt=1;
	int cnt1=1;
	for(int i=1;i<=m;i++){
		if(cnt==1){
			while(cnt<=n){
				mapn[cnt][i]=b[cnt1++];
				if(cnt==n) break;
				cnt++;
			}
			
		}
		else if(cnt==n){
			while(cnt>=1){
				mapn[cnt][i]=b[cnt1++];
				if(cnt==1) break;
				cnt--;
			}
		}
	}
}
void find(int r){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapn[i][j]==r){
				ansn=i,ansm=j;
			}
		}
	}
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	swapn();
	px();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<mapn[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	find(r);
	cout<<ansm<<"  "<<ansn;
//	for(int i=1;i<=n*m;i++){
//		cout<<b[i]<<" ";
//	}
	return 0;
} 
