#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int dp[5005][5005];
int a[500005];
int xor1(int a, int b){
//	cout<<"."<<endl;
	int ax[5005],bx[5005];
	int t1=max(a,b),t2=min(a,b);
	int num1=0,num2=1;
	while(t1>0){
	//	cout<<"."<<endl;
		num1++;
		ax[num1]=t1%2;
		cout<<"ori="<<t1<<" "<<ax[num1]<<" pos="<<num1<<endl;
		t1/=2;
		cout<<"left="<<t1<<endl;
	}
	while(t2>0){
	//	cout<<"."<<endl;
		num2++;
		bx[num2]=t2%2;
		t2/=2;
	}
	int ans[5005];
	int numm=num1;
	while(numm>=1){
	//	cout<<"."<<endl;
		cout<<numm<<" "<<ax[numm]<<" "<<bx[numm]<<endl;
		if(num2<numm){
			ans[numm] = ax[numm];
		}
		else{
			ans[numm] = ax[numm] || bx[numm];
		}
		numm--;	
	}
	int anss=0;
	for(int i=1;i<=num1;i++){
	//	cout<<ans[i]<<endl;
	//	cout<<"."<<endl;
		int mul=1;
		for(int j=1;j<=i-1;j++){
			mul*=2;
		}
	//	cout<<anss<<endl;
		anss+=mul*ans[i];
	}
	return anss;
}
signed main(){
	//	freopen("xor.in","r",stdin);
	//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==2){
		cout<<0<<endl;
		return 0; 
	}

	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=(a[i]==k);
	}
	bool flag =true;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			flag=false;
		}
	}
	if(flag==true&&k==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int len=2;len+i-1<=n;len++){
			int j=len+i-1;
			for(int k=i;k<j;k++){
				dp[i][j] =max(dp[i][k]+dp[k+1][j],max(dp[i][j],xor1(dp[k+1][j],dp[i][k])));
			}
		}
	}
	cout<<dp[1][n];
	return 0;
} 
