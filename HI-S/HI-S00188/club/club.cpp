#include<bits/stdc++.h>
using namespace std;
int t;
int mapp[100001][6],f[100001],tempt[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		memset(f,0,sizeof f);
		memset(tempt,0,sizeof tempt);
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>mapp[j][k];
			}
		}
		for(int j=1;j<=n;j++){
			int s=0,s1=0;
			for(int k=1;k<=3;k++){
				s1=f[j];
				f[j]=max(f[j],(f[j-1]+mapp[j][k]));
				tempt[s]++;
			}
			
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
