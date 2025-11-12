#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[101];
int main() {
	//Ren5Jie4Di4Ling5%
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int max1=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]>max1&&b[j]<=n/2){
					max1=a[i][j];
					b[j]++;
				}
			}
			ans+=max1;
		}
		cout<<ans;
	}
	return 0;
}
