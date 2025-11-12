#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int a[3][n+1];
		int m1=0,m2=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[j][i];
				if(a[j][i]>=m1){
					m1=a[j][i];
				}
			}
			m2+=m1;
		}
		cout<<m2<<endl;
	}
	return 0;
}
