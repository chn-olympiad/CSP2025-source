#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,a[3][100001]={0};
		cin>>n;
		int m=n/2,maxn=0;
		for(int i=0;i<n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
		}
		int c=a[0][0]+a[1][1];
		int d=a[0][0]+a[2][1];
		int e=a[1][0]+a[0][1];
		int g=a[1][0]+a[2][1];
		int h=a[2][0]+a[0][1];
		int i=a[2][0]+a[1][1];
		int j=0;
		cout<<max(max(max(max(max(c,d),g),h),i),e);
	}
	return 0;
}
