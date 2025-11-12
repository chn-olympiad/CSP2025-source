#include <bits/stdc++.h>
using namespace std;
long long a[100001][4],t,n,s[4],an,m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		m=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(j==i)continue;
				else if(a[1][i]+a[2][j]>m)m=a[1][i]+a[2][j];
			}
			
		}
		cout<<m;
	}
	return 0;
}

