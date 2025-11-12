#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pll;
int n,t;
const int N=100010;
int a[N][10],f[N][10];
int idx[N],d[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];

		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
                if(d[j]<n/2 && idx[i]!=1){
                    f[i][j]=max(f[i][j],f[i-1][j]+a[i][j]);
                    d[j]++;
                idx[i]++;
			}

		}

	}cout<<f[n][3]<<endl;
	}
	return 0;
}
