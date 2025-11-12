#include<bits/stdc++.h>
using namespace std;
int a1[100005];
int a2[100005];
int a3[100005];
int aj[100005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out,","w",stdout);
	int n,m,k,sum;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
			for(int j=1;j<=k;j++){
		cin>>aj[j];
		sum+=aj[j]/2;
	}
		}
		cout<<sum;
	return 0;
}
