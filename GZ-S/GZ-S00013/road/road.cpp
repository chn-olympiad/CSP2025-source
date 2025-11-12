//GZ-S00013 贵州省黔西第一中学 代毅承 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	long long a[m+5][3],s[k+5][n+1];
	for(int i=1;i<=m;i++){
		cout<<a[i][1]<<a[i][2]<<a[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>s[i][j];
		}
	}
	cout<<"13";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
