#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,mx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			mx=max(a[i][1],mx);
		}
		cout<<mx<<"\n";
	}
    return 0;
}
