#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,a[N],c=1,r=1,A,dp[20][20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int sum=n*m;
	for(int i=1;i<=sum;i++)scanf("%d",&a[i]);
	A=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				dp[j][i]=a[(i-1)*n+j];
				//cout<<j<<" "<<i<<" "<<(i-1)*4+j<<" "; 
			}
		}
		else{
			for(int j=n,j1=1;j>=1;j--,j1++){
				dp[j][i]=a[(i-1)*n+j1];
				//cout<<j<<" "<<i<<" "<<(i-1)*4+j1<<" "; 
			}
			//cout<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==A)cout<<j<<" "<<i; 
		}
		//cout<<endl;
	}
//    int i;
//    for(i=1;i<=n*m;i++){
//    	if(a[i]==A)break;
//	}
//	cout<<i/n<<" ";
//	if(i%(n*2)==i){
//		cout<<i%(n*2);
//	}
//	else{
//		//cout<<i%n;
//	}
	return 0;
}
