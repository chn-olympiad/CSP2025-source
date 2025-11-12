#include<bits/stdc++.h>
using namespace std;
long long a[200000][5],n,ans=0,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;i++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		cout<<ans;		
	}
	return 0;
}


