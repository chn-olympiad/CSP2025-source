#include<bits/stdc++.h>
using namespace std;
const long long qy=998244353;
int a[5005],n;
bool vis[5005][5005];
int pre[4998][4998];
long long cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int s=0;
	for(int i=1;i+2<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]){
					cnt++;
				}
			}
		}
	}
	cout<<cnt%qy;
	return 0;
}
