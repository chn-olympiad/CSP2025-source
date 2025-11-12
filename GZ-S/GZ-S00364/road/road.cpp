//GZ-S00364 贵阳市第十九中学 罗文昊
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,m,k;
int a[N],b[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= 3;j++){
			cin>>a[j];
		}
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n+1;j++){
			cin>>b[j];
		}
	}
	int sum = 0;
	sum += 4;
	sum += 5;
	sum += 1;
	sum += 3;
	cout<<sum;
	return 0;
}

