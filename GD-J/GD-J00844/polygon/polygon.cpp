#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans=0;
int max_n(int l,int r,int a[]){
	int mx=-1;
	for (int i=l;i<=r;i++){
		if (a[i]>mx){
			mx=a[i];
		}
	}
	return mx;
}
void solve(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=3;i<=n;i++){
		for (int j=1;j<=n-i+1;j++){
			int sum=0;
			for (int k=j;k<=i;k++){
				sum+=a[k];
			}
			int mx=2*max_n(j,i+j-1,a);
			if (sum>mx){
				ans++;
//				printf("i:%d *** j:%d *** sum:%d *** mx:%d\n",i,j,sum,mx);
//				for (int x=j;x<=i+j-1;x++){
//					cout << a[x] << ' ';
//				}
//				cout << '\n';
			}
		}
	}
	cout << ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
