#include<bits/stdc++.h>
using namespace std;
int n,c,a[10005],x[10005][10005];
//vector <int> x[105][105];
long long ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x[i][j]=a[i]^x[i][j-1];
			//cout<<x[i][j]<<' ';
			if(x[i][j]==c)ans++;
		}
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}
