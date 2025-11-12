#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,ans=0;
    cin>>n;
    int a[n+2],b[1000][100];
    for (int i=1;i<=n;i++){
    	cin>>a[i];
	}//输入 
	for (int i=3;i<=n;i++){
		for (int j=1;j<i;j++){
			for (int k=0;k<n;k++){
				if (0){
				b[i][j]=k;
				ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}