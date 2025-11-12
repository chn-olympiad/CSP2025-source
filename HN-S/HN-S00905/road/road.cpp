#include <bits/stdc++.h>
using namespace std;
int sum,v[100005],u[100005],w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i = 1;i <= n;i++){
		cin>>u[i]>>v[i]>>w[i];
		
	}
	int j=1;
	for (int i = 1;i <= k;i++){
		int x=n+1;
		while (x--){
			cin>>u[n+j];
			j++;
		}
	}
	int num=n+(n+1)*k;
	sort(u+1,u+num+1);
	for (int i = 1;i <= n+m;i++){
		sum+=u[i];
	}
	cout<<sum;
	return 0;
}

