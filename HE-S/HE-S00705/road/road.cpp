#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n , m , k , sum;
struct node{
	int u , v , w;
}a[N];

int main(){

	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m ;i ++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		sum += a[i].w;
	}
	for(int i = 1;i <= k;i ++){
		int val;
		cin >> val;
		for(int j = 1;j <= n;j ++){
			int value;
			cin >> value;
		}
	}
	cout << sum; 
	return 0;
}

