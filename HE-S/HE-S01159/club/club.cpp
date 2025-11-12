#include<iostream>
using namespace std;

long long n,t,f[3][10001],df[10001],ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>f[k][j];
			}
		    ans=ans+max(f[1][j],f[2][j],f[3][j]);
			df[n]=ans;
		}
		ans=0;
	}
	for(int i=1;i<=t;i++){
		cout<<df[i]<<endl;
	}
	return 0;
}
