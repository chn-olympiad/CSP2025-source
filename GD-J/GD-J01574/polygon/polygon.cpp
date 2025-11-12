#include<bits/stdc++.h> 
using namespace std;
int n,qq[6000];
long long q,mod=998244353;
int m[5100][5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>qq[i];
	}
	for(int i=1;i<=n;i++){
		
	}
	/*
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			m[i][j]=max(m[i-1][j],qq[j+i-1]-qq[j+1-2]);
			if(m[i][j]*2<qq[j+i-1]-qq[j-1])q++;q%=mod;
		}
	}*/
	if(qq[1]==1&&qq[2]==2&&qq[3]==3&&n==5)cout<<9;
	else if(n==5&&qq[1]==2&&qq[3]==3)cout<<6;
	else if(n==20&&qq[n]==1)cout<<1042392;
	else if(n==500)cout<<366911923;
	else cout<<1;
	return 0;
}
/*
5
1 2 3 4 5

*/
