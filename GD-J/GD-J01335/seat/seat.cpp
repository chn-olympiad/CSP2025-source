#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=15,M=15;
int n,m;
int R;
int sum[N*M];
int seat[N][M];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int lens=n*m;
	for(int i=1;i<=lens;i++){
		cin>>sum[i];
		if(i==1){
			R=sum[i];
		}
	}
	sort(sum+1,sum+lens+1,cmp);
	
	int idx=1;
	int x,y;
	bool f=1;
	for(int j=1;j<=m;j++){
		if(f){
			for(int i=1;i<=n;i++){
				seat[i][j]=sum[idx++];
				if(sum[idx-1]==R){
					x=i;
					y=j;
				}
			}
			f=0;
		}else{
			for(int i=n;i>=1;i--){
				seat[i][j]=sum[idx++];
				if(sum[idx-1]==R){
					x=i;
					y=j;
				}
			}
			f=1;
		}
	}
	cout<<y<<" "<<x;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
