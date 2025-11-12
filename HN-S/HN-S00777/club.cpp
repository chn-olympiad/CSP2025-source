#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sumz;
	cin>>t;
	for(int q=1;q<=t;q++){
		
	int n,a[4][51],sum=0,suma=0;
	cin>>n;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=3;i++){
			if(a[i][j]>a[i-1][j]) sum=std::max(a[i][j],a[i-1][j]);
			}
			suma+=sum;
		}
		cout<<suma<<endl;
	}
	return 0;
}
