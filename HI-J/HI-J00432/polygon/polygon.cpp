#include<bits/stdc++.h>
using namespace std;
const int N=5001;
const int M=998244353;
int a[N][N];
int b[N];
bool cmp(int a,int b){
	return a>b;
}
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		sum+=b[i];
		if(b[i]==1) c++;
	}sort(b+1,b+n+1,cmp);
	if(n==3){
		if(sum>2*b[1]) cout<<1;
		else cout<<0;
	}else if(c==n){
		for(int i=1;i<=n;i++){
			a[1][i]=i;
		}for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++){
				a[i][j]=(a[i-1][j-1]+a[i][j-1])%M;
			}
		}sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][n];
			sum%=M;
		}cout<<sum;
	}else{
		cout<<"你去问老天吧！！！！！！！";
	}
	return 0;
}
